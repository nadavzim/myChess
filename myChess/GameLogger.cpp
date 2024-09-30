#include <iostream>
#include "GameLogger.h"

void GameLogger::onPieceCaptured(Piece* capturedPiece) {
    if (capturedPiece->getycolor()) {
        capturedWhitePieces.push_back(capturedPiece);  // If the piece is white, add it to the white list
    }
    else {
        capturedBlackPieces.push_back(capturedPiece);  // If the piece is black, add it to the black list
    }
}

// Helper function to print captured pieces for a given player
void GameLogger::printCapturedList(const vector<Piece*>& pieces, const string& player) const {
    cout << "Captured " << player << " Pieces: ";
    if (pieces.empty()) {
        cout << "None";
    }
    else {
        for (Piece* p : pieces) {
            cout << p->getIcon() << " ";
        }
    }
    cout << endl;
}

// Method to print captured pieces for both players
void GameLogger::printCapturedPieces() const {
    cout << "\nCaptured Pieces Summary:\n";
    cout << "-------------------------\n";
    printCapturedList(capturedWhitePieces, "White");
    printCapturedList(capturedBlackPieces, "Black");
    cout << "-------------------------\n";
}


Memento GameLogger::saveState() const
{
    return Memento(capturedWhitePieces, capturedBlackPieces);
}

void GameLogger::restoreState(const Memento& memento)
{
    capturedWhitePieces = memento.getWhitePieces();
    capturedBlackPieces = memento.getBlackPieces();
}
