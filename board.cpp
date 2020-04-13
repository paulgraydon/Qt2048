#include "board.h"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>

using namespace std;

Board::Board(int rowCount, int colCount, double valueThresh)
{
    rows = rowCount;
    cols = colCount;
    valueThr = valueThresh;
    pointsScoredLastMove = 0;
    tileCollisionLastMove = false;
    initBoard();
}

Board::Board(const Board& otherBoard)
{
    rows = otherBoard.rows;
    cols = otherBoard.cols;
    valueThr = otherBoard.valueThr;
    initBoard();
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            if (otherBoard.tileBoard[i][j] == NULL)
            {
                tileBoard[i][j] = NULL;
            }
            else
            {
                tileBoard[i][j] = new Tile(*(otherBoard.tileBoard[i][j]));
            }
        }
    }
}

Board::~Board()
{
    // Delete all tiles on the board
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            delete tileBoard[i][j];
        }
    }
}

void Board::initRandomTile()
{
    static default_random_engine generator(time(NULL));
    uniform_real_distribution<double> valDistribution(0.0,1.0);

    int tileRow, tileCol;
    do
    {
        tileRow = rand() % rows;
        tileCol = rand() % cols;
    } while (tileBoard[tileRow][tileCol] != NULL);

    double tileValue = valDistribution(generator);
    if (tileValue <= valueThr) tileBoard[tileRow][tileCol] = new Tile(4);
    else tileBoard[tileRow][tileCol] = new Tile(2);
}

void Board::initBoard()
{
    tileBoard.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        tileBoard[i].resize(cols);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            tileBoard[i][j] = NULL;
        }

    }
}

bool Board::onBoard(int row, int col)
{
    return ((row >= 0)&&(col >= 0)&&(row < rows)&&(col < cols));
}

void Board::moveVertically(int row, int col, Direction dir)
{
    if (tileBoard[row][col] != NULL) {
        bool tileCollision = false;
        int newRow;
        if (dir == UP)
            newRow = row - 1; // Move up
        else
            newRow = row + 1; // Move down

        // Move until tile reaches the edge of the board or another tile is found
        while (onBoard(newRow,col) && tileBoard[newRow][col] == NULL)
        {
            if (dir == UP)
                newRow--;
            else
                newRow++;
        }

        // If the tile would go off the board, stop it
        if (!onBoard(newRow,col))
        {
            if (dir == UP)
                tileBoard[0][col] = tileBoard[row][col];
            else
                tileBoard[rows-1][col] = tileBoard[row][col];
        }
        // If there is a collision with another tile, check the value of that tile
        else
        {
            // If the tile has the same value, upgrade the tile
            if ((tileBoard[newRow][col]->getValue() == tileBoard[row][col]->getValue())&&
                (!tileBoard[newRow][col]->getUpgradedThisMove()))
            {
                tileCollision = true;
                handleCollision(newRow, col);
            }
            // Else, place the moving tile next to it
            else {
                if (dir == UP)
                    tileBoard[newRow+1][col] = tileBoard[row][col];
                else
                    tileBoard[newRow-1][col] = tileBoard[row][col];
            }
        }
        // Remove original tile
        if ((dir == UP && newRow+1 != row)||(dir == DOWN && newRow-1 != row)||tileCollision)
            tileBoard[row][col] = NULL;

        if (tileCollision)
            tileCollisionLastMove = true;
    }
}

void Board::moveHorizontally(int row, int col, Direction dir)
{
    if (tileBoard[row][col] != NULL)
    {
        bool tileCollision = false;
        int newCol;
        if (dir == RIGHT)
            newCol = col + 1; // Move to the right
        else
            newCol = col - 1; // Move to the left

        // Move until tile reaches the edge of the board or another tile is found
        while (onBoard(row,newCol) && tileBoard[row][newCol] == NULL)
        {
            if (dir == RIGHT)
                newCol++;
            else
                newCol--;
        }

        // If the tile would go off the board, stop it
        if (!onBoard(row,newCol))
        {
            if (dir == RIGHT)
                tileBoard[row][cols-1] = tileBoard[row][col];
            else
                tileBoard[row][0] = tileBoard[row][col];
        }
        // If there is a collision with another tile, check the value of that tile
        else
        {
            // If the tile has the same value, upgrade the tile
            if ((tileBoard[row][newCol]->getValue() == tileBoard[row][col]->getValue())&&
                (!tileBoard[row][newCol]->getUpgradedThisMove()))
            {
                tileCollision = true;
                handleCollision(row, newCol);
            }
            // Else, place the moving tile next to it
            else {
                if (dir == RIGHT)
                    tileBoard[row][newCol-1] = tileBoard[row][col];
                else
                    tileBoard[row][newCol+1] = tileBoard[row][col];
            }
        }
        // Remove original tile
        if ((dir == RIGHT && newCol-1 != col)||(dir == LEFT && newCol+1 != col)||tileCollision)
            tileBoard[row][col] = NULL;

        if (tileCollision) tileCollisionLastMove = true;
    }
}

void Board::handleCollision(int collRow, int collCol)
{
    tileBoard[collRow][collCol]->upgradeTile();
    tileBoard[collRow][collCol]->setUpgradedThisMove(true);
    pointsScoredLastMove += tileBoard[collRow][collCol]->getValue();
}

bool Board::changedState(Board &otherBoard) const
{
    if ((rows != otherBoard.rows) || (cols != otherBoard.cols)) return false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (((tileBoard[i][j] == NULL && otherBoard.tileBoard[i][j] != NULL)||
                 (tileBoard[i][j] != NULL && otherBoard.tileBoard[i][j] == NULL))||
                    ((tileBoard[i][j] != NULL && otherBoard.tileBoard[i][j] != NULL)&&
                   tileBoard[i][j]->getValue() != otherBoard.tileBoard[i][j]->getValue()))
                return true;
        }
    }
    return false;
}

void Board::endCurrentMove()
{
    tileCollisionLastMove = false;
    pointsScoredLastMove = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (tileBoard[i][j] != NULL)
            {
                tileBoard[i][j]->setUpgradedThisMove(false);
            }
        }
    }
}

void Board::resetBoard()
{
    pointsScoredLastMove = 0;
    tileCollisionLastMove = false;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            delete tileBoard[i][j];
            tileBoard[i][j] = NULL;
        }
    }

    initRandomTile();
    initRandomTile();
}

Tile* Board::getTile(int row, int col)
{
    return tileBoard[row][col];
}

QString Board::getTileValue(int tileIndex)
{
    int tileRow;
    int tileCol;
    int tileValue;

    tileRow = tileIndex/rows;
    tileCol = tileIndex%rows;

    if (tileBoard[tileRow][tileCol] == NULL) return(QString());
    else
    {
        tileValue = getTile(tileRow, tileCol)->getValue();
        return(QString::number(tileValue));
    }
}

int Board::getTileValueForColor(int tileIndex)
{
    int tileRow;
    int tileCol;
    int tileValue;

    tileRow = tileIndex/rows;
    tileCol = tileIndex%rows;

    if (tileBoard[tileRow][tileCol] == NULL) return(0);
    else
    {
        tileValue = getTile(tileRow, tileCol)->getValue();
        return(tileValue);
    }
}

void Board::move(Direction dir)
{
    Board boardCopy(*this);
    endCurrentMove();

    switch (dir) {
    case UP:
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                moveVertically(i, j, UP);
            }
        }
        break;
    case DOWN:
        for (int i = rows-1; i >= 0; i--)
        {
            for (int j = 0; j < cols; j++)
            {
                moveVertically(i, j, DOWN);
            }
        }
        break;
    case LEFT:
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                moveHorizontally(i, j, LEFT);
            }
        }
        break;
    case RIGHT:
        for (int i = 0; i < rows; i++)
        {
            for (int j = cols-1; j >= 0; j--)
            {
                moveHorizontally(i, j, RIGHT);
            }
        }
    }

    // If the board has changed, place a new random tile
    if (changedState(boardCopy))
    {
        initRandomTile();
    }

    //notifyObservers();
}

bool Board::isFull() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (tileBoard[i][j] == NULL) return false;
        }
    }
    return true;
}

bool Board::canMove() const
{
    if (isFull())
    {
        // Try to make a new move on a copy of the board
        Board newBoard(*this);
        newBoard.move(UP);
        if (changedState(newBoard)) return true;
        newBoard.move(DOWN);
        if (changedState(newBoard)) return true;
        newBoard.move(LEFT);
        if (changedState(newBoard)) return true;
        newBoard.move(RIGHT);
        if (changedState(newBoard)) return true;

        // If everything above failed, then no move is possible
        return false;
    }
    else
    {
        return true;
    }
}
