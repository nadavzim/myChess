#include"Pawn.h"

bool Pawn::validMove(int xDst, int yDst, bool isKill)
{
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);

    // Normal move: one square forward or two squares forward on the first move
    if (xDiff == 0) {
        return (yDiff == 1 || yDiff == 2 && moved == false);
    }

    else if (isKill && (xDiff == 1 && yDiff == 1)) // Attack step (remind - the check if there is a piece to kill is in the Board responsebility)
        return true;
    return false;
}

Piece* Pawn::clone() const {
    Pawn* temp = new  Pawn(xcor, ycor, color);
    if (moved)
        temp->setMoved();
    if (!alive)
        temp->setDead();
    return temp;

}