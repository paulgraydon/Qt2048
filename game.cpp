#include "game.h"

Game::Game(int rowCount, int colCount)
{
    gameScore = 0;
    gameBoard = new Board(rowCount, colCount);
}

Game::~Game()
{
    delete gameBoard;
}

void Game::restartGame()
{
    gameBoard->resetBoard();
    gameOver = false;
    gameScore = 0;
}

void Game::move(Direction dir)
{
    // Perform move on the board
    gameBoard->move(dir);

    // Update score if there was a tile collision this move
    if (gameBoard->getTileCollisionLastMove()) gameScore += gameBoard->getPointsScoredLastMove();

    // Game over if no move is possible
    if (!gameBoard->canMove()) gameOver = true;
}

bool Game::checkGameState()
{
    for (int i = 0; i < gameBoard->getDimension(); ++i)
    {
        for (int j = 0; j < board->getDimension(); ++j)
            if (board->getTile(i,j) != NULL && board->getTile(i,j)->getValue() == WINNING_VALUE)
                return true;
    }


    return false;
}
