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
