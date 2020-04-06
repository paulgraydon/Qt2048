#ifndef GAME_H
#define GAME_H

#define WIN_VALUE 2048 // Define macro for winning value

#include "board.h"


class Game
{
public:
    Game(int rowCount = 4, int colCount = 4);
    ~Game();
    void restartGame();
    Board* getGameBoard() const {return gameBoard;}
    void move(Direction dir);
    int getGameScore() const {return gameScore;}
    bool isGameOver(){return gameOver;}
    bool isGameWon();


private:
    Board* gameBoard;
    int gameScore;
    bool gameOver;
};

#endif // GAME_H
