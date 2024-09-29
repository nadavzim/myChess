#include "pch.h"
#include "CppUnitTest.h"
#include "C:\\Users\\nadav\\source\\repos\\myChess\\myChess\\Board.h""

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTests
{
    TEST_CLASS(BoardTests)
    {
    public:
        TEST_METHOD(TestInitBoard)
        {
            Board board;
            board.init();

            // Check the position of a few key pieces to ensure proper initialization
            Piece* whiteRook = board.findPiece('A', '1');  // a1
            Piece* blackKing = board.findPiece('E', '8');  // e8

            Assert::IsNotNull(whiteRook, L"White rook should be at a1");
            Assert::IsTrue(whiteRook->getKey() == 'R', L"Piece at a1 should be a rook");

            Assert::IsNotNull(blackKing, L"Black king should be at e8");
            Assert::IsTrue(blackKing->getKey() == 'K', L"Piece at e8 should be the king");
        }
    };
}
