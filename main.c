#include <stdio.h>
#include "functions.h"
#include "variables.h"

int main() {

    while(!getGameOver()) {
        updateBoard(doMove());
        nextTurn();
    }

}
