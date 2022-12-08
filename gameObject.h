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
    int score = 0;
    font ffont;
public:

    Game();
    GameState checkState();
    void changeState(GameState);
    void addPoint();
    int getScore();
    void displayYourScore(SDL_Plotter&);
    void resetScore();
    void initialize(ifstream&);
    void saveToFile(ofstream&);
    void printScoreInGame(SDL_Plotter&);
    void printScorePostGame(SDL_Plotter&);

};



#endif /* gameObject_h */
