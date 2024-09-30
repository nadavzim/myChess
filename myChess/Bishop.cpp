#include"Bishop.h"

bool Bishop::validMove(int xDst, int yDst, bool isKill) {
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);

    // Check if the move is diagonal
    if (xDiff != yDiff) {
        return false;
    }

    return true;
}

Bishop* Bishop::clone() const {
    Bishop* temp = new  Bishop(xcor, ycor, color);
    if (!alive)
        temp->setDead();
    return temp;

}