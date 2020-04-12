#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

#include <QVector>
#include <QString>
#include <QDebug>

using namespace std;

class Tile;

enum Direction {UP, DOWN, LEFT, RIGHT};

class Board
{
public:
    Board(int rowCount, int colCount, double valueThr = 0.3);
    Board(const Board& otherBoard);
    ~Board();

    // Public methods accessed by Game class
    void resetBoard(); // Reset board to beginning game state
    int getRowCount() {return rows;}
    int getColCount() {return cols;}
    Tile* getTile(int row, int col);
    QString getTileValue(int tileIndex); // Return tile value by index, under form of a QString
    int getTileValueforColor(int tileIndex);
    void move(Direction dir);
    bool isFull() const;
    int getPointsScoredLastMove() const {return pointsScoredLastMove;}
    bool getTileCollisionLastMove() const {return tileCollisionLastMove;}
    bool canMove() const;

private:
    int rows;
    int cols;
    double valueThr; // Probability of spawning a 4 instead of a 2
    QVector<QVector<Tile*>> tileBoard;
    int pointsScoredLastMove;
    bool tileCollisionLastMove;

    // Private internal methods that change board state
    void initRandomTile();
    void initBoard(); // Create empty board
    bool onBoard(int row, int col); // Checks if given coordinates are within the board's limits
    void moveVertically(int row, int col, Direction dir);
    void moveHorizontally(int row, int col, Direction dir);
    void handleCollision(int collRow, int collCol); // Handle collision of two tiles
    bool changedState(Board& otherBoard) const; // Check if board is different from the argument board
    void endCurrentMove(); // Reset some parameters before next move
};

#endif // BOARD_H
