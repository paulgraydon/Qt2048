#ifndef GAME_H
#define GAME_H

#include "board.h"


class Game
{
public:
    Game(int rows, int cols);
    ~Game();
    Board* getGameBoard() const {return gameBoard;}
    int getGameScore() const {return gameScore;}
    void checkGameState();
    bool gameWon();

private:
    int rows;
    int cols;
    Board* gameBoard;
    int gameScore;
    bool gameOver;
};

#endif // GAME_H
