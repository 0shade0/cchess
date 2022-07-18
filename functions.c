#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "printing.h"

bool checkIfValidPiece(int x, int y, char board[8][8][2], int player) {
    if(x < 0 || x > 7 || y < 0 || y > 7) {
        printf("Invalid space selected! Try again!\n");
        return false;
    }

    char piece[2];
    strcpy(piece, board[x][y]);

    if(piece[0] == 'x') {
        printf("Empty space selected! Try again!\n");
        return false;
    } else {
        int number;
        if(board[x][y][1] == '1') {
            number = 0;
        } else if(board[x][y][1] == '2') {
            number = 1;
        }

        if(number != player) {
            printf("Selected piece belongs to the other player! Try again!\n");
            return true;
        } else {
            return true;
        }
    }
}

void doMove(char board[8][8][2], int player) {
    printf("Player %d turn:\n\n", player + 1);
    printBoard(board, -1, -1);

    int x, selectedRow, selectedColumn;
    char y;

    bool selected = false;
    while(!selected) {
        printf("Select piece:");
        fflush(stdin);
        scanf("%c %d", &y, &x); // e.g. D5

        selectedRow = 8 - x;
        selectedColumn = (int) (toupper(y) - 'A');

        selected = checkIfValidPiece(selectedRow, selectedColumn, board, player);
    }

    printBoard(board, selectedRow, selectedColumn);

    // choose where to move piece

    // printBoard(board, x, y);
}
