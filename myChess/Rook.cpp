#include"Rook.h"

bool Rook::validMove(int xDst, int yDst, bool isKill) {
    if (xcor != xDst && ycor != yDst) {
        return false;
    }
    else
        return true;
}

Rook* Rook::clone() const {
    Rook* temp = new  Rook(xcor, ycor, color);
    if (!alive)
        temp->setDead();
    return temp;
}