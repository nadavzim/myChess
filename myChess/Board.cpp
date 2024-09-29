#include "Board.h"
#include <string>

//Board::Board() {
	//picecs.push_back(bPieces);  // Add black pieces
	//picecs.push_back(wPieces);  // Add white pieces
//}

void Board::print() {
	cout << endl;
	// Print column labels (a-h)
	for (char s = 'a'; s <= 'h'; ++s)
		cout << ' ' << s << ' ';
	cout << endl;

	for (int i = size; i > 0; i--)
	{
		for (int j = 1; j <= size; j++)
		{
			Piece* p = findPiece(j, i);
			if (p && p->getAlive())
				cout << " " << p->getIcon() << " ";
			else
				cout << " - ";
		}
		cout << " " << i << endl;
	}
	cout << endl;
}

// a
void Board::addPiece(char type, int x, int y, bool isWhite) {
	Piece* piece = nullptr;
	switch (type) {
	case 'P': piece = new Pawn(x, y, isWhite); break;
	case 'R': piece = new Rook(x, y, isWhite); break;
	case 'N': piece = new Knight(x, y, isWhite); break;
	case 'B': piece = new Bishop(x, y, isWhite); break;
	case 'Q': piece = new Queen(x, y, isWhite); break;
	case 'K': piece = new King(x, y, isWhite); break;
	}
	if (piece != nullptr) {
		if (isWhite) {
			picecs[0].push_back(piece);
		}
		else {
			picecs[1].push_back(piece);
		}
	}
}

int Board::chrToInt(char cor)
{
	if (cor <= '8' && cor >= '1')
		return cor - '0';
	else if (cor >= 'A' && cor <= 'H')
		return cor - 'A' + 1;
	else
		return -1;

}

/*normal chess init */
void Board::init() {
	for (int i = 1; i <= size; i++) {
		addPiece('P', i, 2, false); // White Pawns
		addPiece('P', i, 7, true); // Black Pawns
	}

	// Black Pieces
	addPiece('R', 1, 1, false);
	addPiece('R', 8, 1, false);
	addPiece('N', 2, 1, false);
	addPiece('N', 7, 1, false);
	addPiece('B', 3, 1, false);
	addPiece('B', 6, 1, false);
	addPiece('Q', 4, 1, false);
	addPiece('K', 5, 1, false);

	// White Pieces
	addPiece('R', 1, 8, true);
	addPiece('R', 8, 8, true);
	addPiece('N', 2, 8, true);
	addPiece('N', 7, 8, true);
	addPiece('B', 3, 8, true);
	addPiece('B', 6, 8, true);
	addPiece('Q', 4, 8, true);
	addPiece('K', 5, 8, true);


	this->print();
}

Piece* Board::findPiece(char x, char y) {
	return findPiece(toupper(x) - 'A' + 1, y - '0');
}

//  findPiece to return pieces in specific (x,y) regardless of their alive status 
Piece* Board::findPiece(int x, int y) {
	for (auto& pieceList : picecs) {
		for (Piece* v : pieceList) {
			if (v->getxcor() == x && v->getycor() == y) {
				return v;  // Return piece 
			}
		}
	}
	return nullptr;
}


bool Board::makeMove(string src, string dst, bool turn) {
	// Convert board positions from strings to integer coordinates.
	int xSrc = chrToInt(src[0]), ySrc = chrToInt(src[1]);
	int xDst = chrToInt(dst[0]), yDst = chrToInt(dst[1]);

	// Find pieces at source and destination positions.
	Piece* srcPiece = findPiece(xSrc, ySrc);
	Piece* dstPiece = findPiece(xDst, yDst);

	// Validate the move.
	if (!srcPiece || srcPiece->getycolor() != turn) // No piece at src or not the player's turn
		return false;
	if (dstPiece && dstPiece->getycolor() == turn) // Destination occupied by same color
		return false;

	bool isPawnAttack = (dstPiece && srcPiece->getKey() == 'P');

	// check if the move is correct for the piece.
	if (!srcPiece->validMove(xDst, yDst, isPawnAttack))
		return false;

	// Ensure the path is clear for all pieces except the knight (H).
	if (srcPiece->getKey() != 'H' && !clearPath(xSrc, ySrc, xDst, yDst))
		return false;

	// Capturing an opponent's piece.
	if (dstPiece) {
		if (dstPiece->getKey() == 'K') {
			cout << "Player " << (turn + 1) << " wins!\n";
		}
		else {
			dstPiece->setDead();
		}
	}

	srcPiece->move(xDst, yDst);

	// Special handling for pawn double moves on the first move.
	if (srcPiece->getKey() == 'P' && abs(yDst - ySrc) == 2)
		dynamic_cast<Pawn*>(srcPiece)->setMoved();

	return true; // Successful move.
}

bool Board::clearPath(int xSrc, int ySrc, int xDst, int yDst)
{
	// Direction of movement along the x and y axes
	int xStep = (xDst > xSrc) ? 1 : (xDst < xSrc) ? -1 : 0;  // +1, -1, or 0 for no movement in x
	int yStep = (yDst > ySrc) ? 1 : (yDst < ySrc) ? -1 : 0;  // +1, -1, or 0 for no movement in y

	// Check if the move is valid (straight or diagonal)
	if (xStep != 0 && yStep != 0 && abs(xDst - xSrc) != abs(yDst - ySrc)) {
		return false;  
	}

	// Start checking from the next position after the source
	int x = xSrc + xStep;
	int y = ySrc + yStep;

	// Go on the path between (xSrc, ySrc) and (xDst, yDst)
	while (x != xDst || y != yDst) {
		if (findPiece(x, y)) {
			return false;  // Path is blocked by a piece
		}
		x += xStep;
		y += yStep;
	}

	return true;  // Path is clear
}
