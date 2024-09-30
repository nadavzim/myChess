#pragma once
#include "Pieces.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
class PieceFactory {
public:
    // Factory method to create pieces
    static Piece* createPiece(char type, int x, int y, bool isWhite);
};

