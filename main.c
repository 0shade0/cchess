#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

int main() {

    bool gameOver = false; // boolean : true/false
    int player = 0;

    char board[8][8][2] = {
        {"p2","p2","p2","p2","p2","p2","p2","p2"},
        {"R2","N2","B2","Q2","K2","B2","N2","R2"},
        {"xx","xx","xx","xx","xx","xx","xx","xx"},
        {"xx","xx","xx","xx","xx","xx","xx","xx"},
        {"xx","xx","xx","xx","xx","xx","xx","xx"},
        {"xx","xx","xx","xx","xx","xx","xx","xx"},
        {"R1","N1","B1","K1","Q1","B1","N1","R1"},
        {"p1","p1","p1","p1","p1","p1","p1","p1"},
    };

    while(!gameOver) {
        doMove(board, player);
        player = 1 - player;
    }

}
