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

void Game::setCell(int row, int col, int value)
{
    if ((row<0)||(col<0)||(row>rows)||(col>cols))
    {
        // Throw custom exception
        throw 1;
    }

    gameGrid[row][col]=value;
}

void Game::gameInit()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> rowDistribution(0,rows);
    std::uniform_int_distribution<int> colDistribution(0,cols);
    std::uniform_real_distribution<double> valDistribution(0.0,1.0);

    row1 = rowDistribution(generator);
    row2 = rowDistribution(generator);

    col1 = colDistribution(generator);
    col2 = colDistribution(generator);

    while((row1 == row2)&&(col1 == col2))
    {
        row2 = rowDistribution(generator);
        col2 = colDistribution(generator);
    }

    valueRand = valDistribution(generator);
}
