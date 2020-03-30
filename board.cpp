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
    if (tileValue <= valueThr) tileBoard[tileRow][tileCol]->setValue(4);
    else tileBoard[tileRow][tileCol]->setValue(2);
}
