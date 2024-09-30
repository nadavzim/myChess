#include"King.h"

bool King::validMove(int xDst, int yDst, bool isKill) {
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);
    if (xDiff > 1 || yDiff > 1)
        return false;
    else
        return true;
}

King* King::clone() const {
    King* temp = new King(xcor, ycor, color);
    if (!alive)
        temp->setDead();
    return temp;

}