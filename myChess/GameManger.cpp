#include "GameManger.h"
#include "GameLogger.h"

/*This function implements the Singleton design pattern, ensures that only one instance of GameManger exists.*/
static GameManger& getInstance() {
    static GameManger instance;
    return instance;
}

/**
 * Initializes the GameManager.
 */
void GameManger::init() {
    b.init();
    piecesUndoStack.push(b.saveState());
    capturedUndoStack.push(logger.saveState());
    b.registerObserver(&logger);
}

/**
 * Prints the current state of the board.
 */
void GameManger::printBoard() {
    b.print();
}

/**
 * Checks if the move command input is valid.
 * @param s The move command input.
 * @return True if the move command input is valid, false otherwise.
 */
bool GameManger::validMoveCmdInput(const string& s) {
    if (s[1] >= '1' && s[1] <= '8')
        if (toupper(s[0]) >= 'A' && toupper(s[0]) <= 'H')
            return true;
    return false;
}

/**
 * Makes a move on the board.
 * @param move The move to be made.
 * @param turn The current turn.
 * @return True if the move is valid and successful, false otherwise.
 */
bool GameManger::makeMove(const string& move) {
    if (move.size() != 4) return false;

    string src = move.substr(0, 2);
    string dst = move.substr(2, 4);

    if (validMoveCmdInput(src) && validMoveCmdInput(dst)) {
        bool result = b.makeMove(src, dst, turn);

        if (result) {
            printGameState();
            turn = !turn;
            saveState();
        }

        return result;
    }

    return false;
}

/**
 * Prints the current state of the board and captured pieces.
 */
void GameManger::printGameState() {
    b.print();  // Print the board
    logger.printCapturedPieces();  // Print captured pieces using logger
}

/**
 * Saves the current state of the board and captured pieces.
 */
void GameManger::saveState() {
    piecesUndoStack.push(b.saveState());
    capturedUndoStack.push(logger.saveState());

    clearRedoStacks();  // Clear redo stacks after a new move is made
}

/**
 * Clears the redo stacks when a new move is made.
 */
void GameManger::clearRedoStacks() {
    while (!piecesRedoStack.empty()) piecesRedoStack.pop();
    while (!capturedRedoStack.empty()) capturedRedoStack.pop();
}

/**
 * Helper function to restore a state from the stacks (for undo and redo).
 * @param piecesState The state to restore for the board.
 * @param capturedState The state to restore for the captured pieces.
 */
void GameManger::restoreState(const Memento& piecesState, const Memento& capturedState) {
    b.restoreState(piecesState);
    logger.restoreState(capturedState);
}

/**
 * Undo the last move made on the board.
 */
void GameManger::undo() {
    cout << "Undo...\n";

    if (piecesUndoStack.size() > 1 && capturedUndoStack.size() > 1) {
        // Pop and push the states for undo/redo
        Memento piecesTemp = piecesUndoStack.top();
        piecesUndoStack.pop();
        piecesRedoStack.push(piecesTemp);

        Memento capturedTemp = capturedUndoStack.top();
        capturedUndoStack.pop();
        capturedRedoStack.push(capturedTemp);

        // Restore the previous state
        restoreState(piecesUndoStack.top(), capturedUndoStack.top());

        cout << "Successfully printed the previous move.\n";
        printGameState();
        turn = !turn;
    }
    else {
        cout << "Failed, no more moves to undo.\n";
    }
}

/**
 * Redo the last undone move on the board.
 */
void GameManger::redo() {
    cout << "Redo...\n";

    if (!piecesRedoStack.empty() && !capturedRedoStack.empty()) {
        // Pop and restore the state
        Memento piecesTemp = piecesRedoStack.top();
        piecesRedoStack.pop();
        piecesUndoStack.push(b.saveState());  // Save the current state before redoing
        b.restoreState(piecesTemp);

        Memento capturedTemp = capturedRedoStack.top();
        capturedRedoStack.pop();
        capturedUndoStack.push(logger.saveState());  // Save captured state before redoing
        logger.restoreState(capturedTemp);

        cout << "Successfully printed the next move.\n";
        printGameState();
        turn = !turn;
    }
    else {
        cout << "Failed, no more moves to redo.\n";
    }
}
