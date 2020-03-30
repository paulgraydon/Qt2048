#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <random>


class Game
{
public:
    Game(int rowCount = 4, int colCount = 4);
    ~Game();
    void setCell(int row, int col, int value);
    void gameInit();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void print();
private:
    int rows;
    int cols;
    int* gameScore;
    int** gameGrid;
};

#endif // GAME_H
