#include"Knight.h"

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

Knight* Knight::clone() const {
    Knight* temp = new  Knight(xcor, ycor, color);
    if (!alive)
        temp->setDead();
    return temp;

}