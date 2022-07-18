#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void printSquareRow(int rowNumber, char row[8][2], int selectedColumn) {
    printRowNumber(rowNumber, true);
    for (int column=0; column < 8; column++) {
        printSquare(column, row[column], selectedColumn == column);
    }
    printRowNumber(rowNumber, false);
    printInBetweenRow(rowNumber);
}

void printRowNumber(int row, bool left) {
    printf("%d", 8 - row);
    if(left) {
        printf("  ");
    } else {
        printf("\n");
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

void printBoard(char board[8][8][2], int selectedRow, int selectedColumn) {
    int row;

    printLetterRow(true);

    for(row=0; row < 8; row++) {
        if(row == selectedRow) {
            printSquareRow(row, board[row], selectedColumn);
        } else {
            printSquareRow(row, board[row], -1);
        }
    }

    printLetterRow(false);
}
