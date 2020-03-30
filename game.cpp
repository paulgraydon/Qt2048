#include "game.h"
#include <iostream>
#include <random>

using namespace std;

Game::Game(int rowCount, int colCount)
{
    rows = rowCount;
    cols = colCount;

    // Dynamically allocate matrix
    gameGrid = new int*[rows];
    for (int k=0; k<rows; k++) gameGrid[k] = new int[cols];

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            gameGrid[i][j] = 0;
        }
    }
}

Game::~Game()
{
    if (gameGrid != nullptr)
    {
        for (int i=0; i<rows; i++)
            delete [] gameGrid[i];
        delete [] gameGrid;

        gameGrid = nullptr;
    }
}

void Game::setCellValue(int row, int col, int value)
{
    if ((row<0)||(col<0)||(row>rows)||(col>cols))
    {
        // Throw custom exception
        throw 1;
    }

    gameGrid[row][col]=value;
}

void Game::spawnRandomCell()
{
    default_random_engine generator;
    uniform_int_distribution<int> rowDistribution(0,rows);
    uniform_int_distribution<int> colDistribution(0,cols);
    uniform_real_distribution<double> valDistribution(0.0,1.0);

    cellRow = rowDistribution(generator);
    cellCol = colDistribution(generator);

    while(gameGrid[cellRow][cellCol] != 0)
    {
        cellRow = rowDistribution(generator);
        cellCol = colDistribution(generator);
    }

    valueProb = valDistribution(generator);
    if (valueProb1 <= cellValueThr) cellValue = 4;
    else cellValue = 2;

    setCellValue(cellRow, cellCol, cellValue);
}

void Game::gameInit()
{
    *gameScore = 0;

    spawnRandomCell();
    spawnRandomCell();
}
