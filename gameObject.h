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
public:
    GameState checkState();
    void changeState(GameState);
    //void borderCheck(Snake) const;
    //bool snakeCheck(Snake) const;
    
    
};

#endif /* gameObject_h */
