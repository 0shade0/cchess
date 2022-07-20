#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "printing.h"
#include "variables.h"

bool checkIfValidPiece(int x, int y, char square[2]) {
    if(x < 0 || x > 7 || y < 0 || y > 7) {
        printf("Invalid space selected! Try again!\n\n");
        return false;
    }

    if(square[0] == 'x') {
        printf("Empty space selected! Try again!\n\n");
        return false;
    }

    int number;
    if(square[1] == '1') {
        number = 0;
    } else if(square[1] == '2') {
        number = 1;
    }

    if(number != getPlayer()) {
        printf("Selected piece belongs to the other player! Try again!\n\n");
        return false;
    } else {
        return true;
    }
}

int selectPiece() {
    int x, selectedRow, selectedColumn;
    unsigned char y;

    bool selected = false;
    while(!selected) {
        fflush(stdin);
        printf("Select piece:");
        scanf("%c %d", &y, &x); // e.g. D5
        printf("\n");

        selectedRow = 8 - x;
        selectedColumn = (int) (toupper(y) - 'A');

        selected = checkIfValidPiece(
            selectedRow,
            selectedColumn,
            square(selectedRow,selectedColumn)
        );
    }

    return selectedRow * 10 + selectedColumn;
}

bool checkIfValidMove(int x, int y) {
    return true;
}

int movePiece() {
    int x, selectedRow, selectedColumn;
    unsigned char y;

    bool selected = false;
    while(!selected) {
        fflush(stdin);
        printf("Select square to move:");
        scanf("%c %d", &y, &x); // e.g. D5
        printf("\n");

        selectedRow = 8 - x;
        selectedColumn = (int) (toupper(y) - 'A');

        selected = checkIfValidMove(selectedRow, selectedColumn);
    }

    return selectedRow * 10 + selectedColumn;
}

int doMove() {
    int selection, move, selectedRow, selectedColumn;

    printf("Player %d turn:\n\n", getPlayer() + 1);
    printBoard(-1, -1, true);

    selection = selectPiece();
    selectedRow = selection/10;
    selectedColumn = selection%10;

    printBoard(selectedRow, selectedColumn, false);

    move = movePiece();

    return selection * 100 + move;
}

void updateBoard(int move) {
    int selectionX = (move/1000)%10;
    int selectionY = (move/100)%10;
    int destinationX = (move/10)%10;
    int destinationY = move%10;

    char selectionPiece[2];
    strncpy(selectionPiece, square(selectionX, selectionY), 2);

    char destinationPiece[2];
    strncpy(destinationPiece, square(destinationX, destinationY), 2);

    if(destinationPiece[1] == '2' && getPlayer() == 0) {
        addP1PieceTaken(destinationPiece);
    }

    if(destinationPiece[1] == '1' && getPlayer() == 1) {
        addP2PieceTaken(destinationPiece);
    }

    strncpy(destinationPiece, selectionPiece, 2);

    setSquare(selectionX, selectionY, "xx");
    setSquare(destinationX, destinationY, destinationPiece);

    printBoard(-1, -1, false);
}

void nextTurn() {
    printf("Press any key to end turn...");
    fflush(stdin);
    getchar();

    setPlayer(1 - getPlayer());
}
