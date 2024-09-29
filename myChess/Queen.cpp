#include"Queen.h"
bool Queen::validMove(int xDst, int yDst, bool isKill) {
    int xDiff = abs(xDst - xcor);
    int yDiff = abs(yDst - ycor);

    // Check if the move is either diagonal (like a bishop) or straight (like a rook)
    bool isDiagonalMove = (xDiff == yDiff);
    bool isStraightMove = (xcor == xDst || ycor == yDst);

    if (!isDiagonalMove && !isStraightMove) {
        return false;
    }
    else
        return true;
}

