#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool checkIfValidPiece(int x, int y, char square[2]);

bool checkIfValidMove(int x, int y);

int selectPiece();

int doMove();

void updateBoard(int moveValue);

void nextTurn();
