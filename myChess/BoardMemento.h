#pragma once
#include <vector>
#include "Pieces.h"

class Memento {
private:
    vector<Piece*> blackPieces;
    vector<Piece*> whitePieces;


public:
    // Constructor that deep copies the piece vectors
    Memento(const vector<Piece*>& bPieces, const vector<Piece*>& wPieces) {
        // Deep copy black pieces
        for (const auto& piece : bPieces) {
            if (piece != nullptr) {
                blackPieces.push_back(piece->clone()); // Use clone method
            }
            else {
                blackPieces.push_back(nullptr);
            }
        }

        // Deep copy white pieces
        for (const auto& piece : wPieces) {
            if (piece != nullptr) {
                whitePieces.push_back(piece->clone()); // Use clone method
            }
            else {
                whitePieces.push_back(nullptr);
            }
        }
    }


    // Destructor is now empty - no need to delete the cloned pieces
    ~Memento() = default;

    vector<Piece*> getBlackPieces() const { return blackPieces; }
    vector<Piece*> getWhitePieces() const { return whitePieces; }

};
