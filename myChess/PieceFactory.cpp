#include "PieceFactory.h"

Piece* PieceFactory::createPiece(char type, int x, int y, bool isWhite)
{
        switch (type) {
        case 'P': return new Pawn(x, y, isWhite);
        case 'R': return new Rook(x, y, isWhite);
        case 'N': return new Knight(x, y, isWhite);
        case 'B': return new Bishop(x, y, isWhite);
        case 'Q': return new Queen(x, y, isWhite);
        case 'K': return new King(x, y, isWhite);
        default: return nullptr;  // If type is invalid, return nullptr
        }
}
