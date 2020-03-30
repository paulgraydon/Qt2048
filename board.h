#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QString>

class Tile;

enum Direction {UP, DOWN, LEFT, RIGHT};

class Board
{
public:
    Board(int rows, int cols);
    ~Board();

    // Public methods accessed by Game class
    void boardInit();
    Tile* getTile(int row, int col);
    void move(Direction dir);
    void isFull();

private:
    int rows;
    int cols;
    QVector<QVector<Tile*>> gameBoard;

    // Private internal methods that change board state
    void initRandomTile();
    void moveVertically(int row, int col, Direction dir);
    void moveHorizontally(int row, int col, Direction dir);
};

#endif // BOARD_H
