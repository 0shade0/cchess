#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static char board[8][8][2] = {
    {"R2","N2","B2","Q2","K2","B2","N2","R2"},
    {"p2","p2","p2","p2","p2","p2","p2","p2"},
    {"xx","xx","xx","xx","xx","xx","xx","xx"},
    {"xx","xx","xx","xx","xx","xx","xx","xx"},
    {"xx","xx","xx","xx","xx","xx","xx","xx"},
    {"xx","xx","xx","xx","xx","xx","xx","xx"},
    {"p1","p1","p1","p1","p1","p1","p1","p1"},
    {"R1","N1","B1","K1","Q1","B1","N1","R1"},
};

static int p1NoOfPiecesTaken = 0;
static char p1PiecesTaken[16][2] = {
    "xx","xx","xx","xx","xx","xx","xx","xx",
    "xx","xx","xx","xx","xx","xx","xx","xx"
};

static int p2NoOfPiecesTaken = 0;
static char p2PiecesTaken[16][2] = {
    "xx","xx","xx","xx","xx","xx","xx","xx",
    "xx","xx","xx","xx","xx","xx","xx","xx"
};

static bool gameOver = false; // boolean : true/false
static int player = 0;

char* square(int x, int y) {
    return board[x][y];
}

void setSquare(int x, int y, char square[2]) {
    strncpy(board[x][y], square, 2);
}

char* p1PieceTaken(int x) {
    return p1PiecesTaken[x];
}

void addP1PieceTaken(char piece[2]) {
    strncpy(p1PiecesTaken[p1NoOfPiecesTaken], piece, 2);
    ++p1NoOfPiecesTaken;
}

int getP1NoOfPiecesTaken() {
    return p1NoOfPiecesTaken;
}

char* p2PieceTaken(int x) {
    return p2PiecesTaken[x];
}

void addP2PieceTaken(char piece[2]) {
    strncpy(p2PiecesTaken[p2NoOfPiecesTaken], piece, 2);
    ++p2NoOfPiecesTaken;
}

int getP2NoOfPiecesTaken() {
    return p2NoOfPiecesTaken;
}

bool getGameOver() {
    return gameOver;
}

int getPlayer() {
    return player;
}

void setPlayer(int value) {
    player = value;
}
