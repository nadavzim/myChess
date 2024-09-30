#pragma once
#include <vector>
#include "ChessObserver.h"
#include "Pieces.h"
#include "Queen.h"
#include "BoardMemento.h"
using namespace std;

class GameLogger : public ChessObserver
{
private:
    vector<Piece*> capturedWhitePieces;  // Captured white pieces
    vector<Piece*> capturedBlackPieces;  // Captured black pieces

public:
    void onPieceCaptured(Piece* capturedPiece) override;

    // Helper function to print captured pieces for a given player
    void printCapturedList(const vector<Piece*>& pieces, const string& player) const;

    // Method to print captured pieces for both players
    void printCapturedPieces() const;

    Memento saveState() const;
    void restoreState(const Memento& memento);

};
