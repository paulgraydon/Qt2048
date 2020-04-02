#include "board.h"
#include <random>

using namespace std;

Board::Board(int rowCount, int colCount, double valueThresh)
{
    rows = rowCount;
    cols = colCount;
    valueThr = valueThresh;
}

Board::Board(const Board& otherBoard)
{
    rows = otherBoard.rows;
    cols = otherBoard.cols;
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
    default_random_engine generator;
    uniform_int_distribution<int> rowDistribution(0,rows);
    uniform_int_distribution<int> colDistribution(0,cols);
    uniform_real_distribution<double> valDistribution(0.0,1.0);

    int tileRow, tileCol;
    do
    {
        tileRow = rowDistribution(generator);
        tileCol = colDistribution(generator);
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

void handleCollision(int collRow, int collCol)
{
    tileBoard[collRow][collCol]->upgradeTile();
    tileBoard[collRow][collCol]->setUpgratedThisMove(true);
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

void Board::resetBoard()
{
    pointsScoredLastMove = 0;
    tileCollisionLastMove = false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete tileBoard[i][j];
            tileBoard[i][j] = NULL;
        }
    }

    initRandomTile();
    initRandomTile();
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
