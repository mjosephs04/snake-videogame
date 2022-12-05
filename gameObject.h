
//
//  gameObject.h
//  SDL Practice
//
//  Created by Caleb Beckering on 11/16/22.
//

#ifndef gameObject_h
#define gameObject_h
#include "fruit.h"
enum GameState {START, PLAY, PAUSE, OVER};

class Game{
private:
    GameState currState;
    //SNAKE hissy;
    Fruit apple;
    int score = 0;
public:
    GameState checkState();
    void changeState(GameState);
    //void borderCheck(Snake) const;
    //bool snakeCheck(Snake) const;
    void addPoint();
    int getScore();


};

#endif /* gameObject_h */
