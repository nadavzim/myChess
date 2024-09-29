#include "Pieces.h"

bool Pawn::validMove(int xDst, int yDst, bool isKill)
{
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);

    // Ensure that the pawn does not move backward
    if (yDst <= ycor) {
        return false; // Pawns cannot move backward
    }

    // Normal move: one square forward or two squares forward on the first move
    if (xDiff == 0) { 
        return (yDiff == 1 || yDiff == 2 && moved == false);
    }

    else if (isKill &&( xDiff == 1 && yDiff == 1)) // Attack step (remind - the check if there is a piece to kill is in the Board responsebility)
        return true;
    return false;
}

bool Bishop::validMove(int xDst, int yDst, bool isKill) {
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);

    // Check if the move is diagonal
    if (xDiff != yDiff) {
        return false;
    }

    return true;
}

bool Knight::validMove(int xDst, int yDst, bool isKill) {
    // Check if the move follows the knight's "L" pattern: either 2 in one direction, 1 in the other
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);

    // Check if the move follows the knight's "L" pattern: either 2 in one direction, 1 in the other
    if (!((xDiff == 2 && yDiff == 1) || (xDiff == 1 && yDiff == 2))) {
        return false;
    }
    else
        return true;
}

bool Rook::validMove(int xDst, int yDst, bool isKill){
    if (xcor != xDst && ycor != yDst) {
        return false;
    }
    else 
        return true;
}

bool King::validMove(int xDst, int yDst, bool isKill){
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);
    if (xDiff > 1 || yDiff > 1)
        return false;
    else
        return true;
}

void Piece::move(int xDst, int yDst, bool isKill) {
    xcor = xDst;
    ycor = yDst;
}
