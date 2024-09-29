#include "pch.h"
#include "CppUnitTest.h"
#include "C:\\Users\\nadav\\source\\repos\\myChess\\myChess\\GameManger.h""

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTests
{
    TEST_CLASS(ChessGameTests)
    {
    public:
        TEST_METHOD(TestComplexChessScenario)
        {
            GameManger game;  // Initialize game manager
            bool turn = false;  // White starts (turn = false)

            // Move 1: White pawn e2 to e4
            std::string move1 = "e2e4";
            bool result = game.makeMove(move1, turn);
            Assert::IsTrue(result, L"White pawn should move from e2 to e4 successfully");

            // Check the white pawn's new position (e4)
            Piece* whitePawn = game.getBoard().findPiece('e', '4');
            Assert::IsTrue(whitePawn != nullptr && whitePawn->getKey() == 'P', L"White pawn should be at e4");

            turn = !turn;  // Black's turn

            // Move 2: Black pawn d7 to d5
            std::string move2 = "d7d5";
            result = game.makeMove(move2, turn);
            Assert::IsTrue(result, L"Black pawn should move from d7 to d5 successfully");

            // Check the black pawn's new position (d5)
            Piece* blackPawn = game.getBoard().findPiece('d', '5');
            Assert::IsTrue(blackPawn != nullptr && blackPawn->getKey() == 'P', L"Black pawn should be at d5");

            turn = !turn;  // White's turn

            // Move 3: White queen d1 to h5
            std::string move3 = "d1h5";
            result = game.makeMove(move3, turn);
            Assert::IsTrue(result, L"White queen should move from d1 to h5 successfully");

            // Check the white queen's new position (h5)
            Piece* whiteQueen = game.getBoard().findPiece('h', '5');
            Assert::IsTrue(whiteQueen != nullptr && whiteQueen->getKey() == 'Q', L"White queen should be at h5");

            turn = !turn;  // Black's turn

            // Move 4: Black pawn d5 to e4 (captures White pawn)
            std::string move4 = "d5e4";
            result = game.makeMove(move4, turn);
            Assert::IsTrue(result, L"Black pawn should capture White pawn on e4");

            // Verify the black pawn is now on e4
            blackPawn = game.getBoard().findPiece('e', '4');
            Assert::IsTrue(blackPawn != nullptr && blackPawn->getKey() == 'P', L"Black pawn should be at e4");

            turn = !turn;  // White's turn

            // Move 5: White queen h5 to d5 (captures Black pawn)
            std::string move5 = "h5d5";
            result = game.makeMove(move5, turn);
            Assert::IsTrue(result, L"White queen should capture Black pawn on d5");

            // Check the white queen's new position (d5)
            whiteQueen = game.getBoard().findPiece('d', '5');
            Assert::IsTrue(whiteQueen != nullptr && whiteQueen->getKey() == 'Q', L"White queen should be at d5");

            // Verify the black pawn is dead
            Piece* capturedBlackPawn = game.getBoard().findPiece('d', '5');
            Assert::IsTrue(capturedBlackPawn == whiteQueen, L"Black pawn should be removed from the board after being captured (only White queen should be at d5)");

            // Final output
            Logger::WriteMessage("All complex moves, captures, and piece positions were validated successfully.");
        }
    };
}
