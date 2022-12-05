
//
//  gameObject.cpp
//  SDL Practice
//
//  Created by Caleb Beckering on 11/16/22.
//

#include <stdio.h>
#include "gameObject.h"

/*void Game::borderCheck(Snake) const{
    if(xLoc[0] == -SIZE || xLoc[0] == NUM_COL){
        gameOver = true;
    }
    if(yLoc[0] == -SIZE || yLoc[0] == NUM_ROW){
        gameOver = true;
    }
}*/

GameState Game::checkState(){
    return currState;
}

void Game::changeState(GameState n){
    currState = n;
}

void Game::addPoint(){
    score++;
}
int Game::getScore(){
    return score;
}
