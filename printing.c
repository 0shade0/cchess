#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "variables.h"

void printRowNumber(int row, bool left) {
    printf("%d", 8 - row);
    if(left) {
        printf("  ");
    } else {
        printf("\n");
    }
}

void printInBetweenColumns(int column) {
    if(column == 7) {
        printf(" ");
    } else {
        printf("|");
    }
}

void printInBetweenRow(int row) {
    if(row == 7 || row == 0) {
        printf("   ---------------------------------------   \n");
    } else {
        printf("   ----+----+----+----+----+----+----+----   \n");
    }
}

void printLetterRow(bool top) {
    if(top) {
        printf("    A    B    C    D    E    F    G    H     \n");
        printInBetweenRow(0);
    } else {
        printf("    A    B    C    D    E    F    G    H     \n\n");
    }
}

void printSquareSelection(bool selected, bool left) {
    if(!selected) {
        printf(" ");
    } else if(left) {
        printf(">");
    } else {
        printf("<");
    }
}

void printSquare(int column, char square[2], bool selected) {
    printSquareSelection(selected, true);
    switch(square[0]) {
        case 'x':
            printf("  ");
            break;

        default:
            printf("%c%c",
               square[0],
               square[1]
            );
    }
    printSquareSelection(selected, false);
    printInBetweenColumns(column);
}

void printSquareRow(int rowNumber, int selectedColumn) {
    printRowNumber(rowNumber, true);
    for (int column=0; column < 8; column++) {
        printSquare(column, square(rowNumber, column), selectedColumn == column);
    }
    printRowNumber(rowNumber, false);
    printInBetweenRow(rowNumber);
}

void printPiecesTaken() {
    int p1No = getP1NoOfPiecesTaken();
    int p2No = getP2NoOfPiecesTaken();
    if(p1No == -1 || p2No == -1) return;

    char piece[2];

    printf("Player 1 pieces taken(%d): ", p1No);
    for(int i=0; i < p1No; i++) {
        strncpy(piece, p1PieceTaken(i), 2);
        printf("%c%c ", piece[0], piece[1]);
    }
    printf("\n");

    printf("Player 2 pieces taken(%d): ", p2No);
    for(int i=0; i < p2No; i++) {
        strncpy(piece, p2PieceTaken(i), 2);
        printf("%c%c ", piece[0], piece[1]);
    }

    printf("\n");

    printf("\n");
}

void printBoard(int selectedRow, int selectedColumn, bool piecesTaken) {
    int row;

    if(piecesTaken) {
        printPiecesTaken();
    }

    printLetterRow(true);

    for(row=0; row < 8; row++) {
        if(row == selectedRow) {
            printSquareRow(row, selectedColumn);
        } else {
            printSquareRow(row, -1);
        }
    }

    printLetterRow(false);
}
