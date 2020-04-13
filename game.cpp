#include "game.h"
#include "qtile.h"

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
    if (!gameBoard->canMove())
    {
        gameOver = true;
    }
}

bool Game::isGameWon()
{
    for (int i = 0; i < gameBoard->getRowCount(); i++)
    {
        for (int j = 0; j < gameBoard->getColCount(); j++)
            if (gameBoard->getTile(i,j) != NULL && gameBoard->getTile(i,j)->getValue() == WIN_VALUE)
                return true;
    }
    return false;
}
