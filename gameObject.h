//
//  gameObject.h
//  groupProject(final)
//
//  Created by Caleb Beckering on 12/6/22.
//

#ifndef gameObject_h
#define gameObject_h

#include "fruit.h"
#include "constants.h"
#include "font.h"
#include "snake.h"
#include "scoreboard.h"


class Game{
private:
    GameState currState;
    snake hissy;
    Fruit apple;
    int score = 0;
    font ffont;
    Scoreboard highScore;
public:
    
    Game();
    GameState checkState();
    void changeState(GameState);
    void addPoint();
    int getScore();
    void displayYourScore(SDL_Plotter&);

};



#endif /* gameObject_h */
