#include"Pieces.h"
#pragma once

class ChessObserver {
public:
    virtual void onPieceCaptured(Piece* capturedPiece) = 0;
};

