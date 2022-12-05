#include <iostream>
#include <cmath>
#include <ctime>
#include <SDL2/SDL.h>
#include "SDL_Plotter.h"
#include "gameObject.h"
#include "snake.h"
#include "fruit.h"
#include "sound.h"
using namespace std;

int main(int argc, char** argv) {
// Data Abstraction
    char key;
    bool isPaused;
    SDL_Plotter g(NUM_ROW, NUM_COL);
    snake hiss(3);
    Fruit apple;
    Direction dir;
    Game fun;
    Sound soundEffects(g);

    color black;

    srand(time(0));
    apple.setPoint((((rand()% (1000 / SIZE -1 )) +1) * SIZE) ,
                   (((rand()% (1000 / SIZE -1 )) +1) * SIZE));

// Main Loop
    hiss.setColorHead();
    while(!g.getQuit()){
    //UI
        if(g.kbhit()){
            key = g.getKey();

            switch(key){
                case UP_ARROW:
                    if(hiss.getDir() != DOWN){
                        hiss.setDir(UP);
                    }
                    break;
                case DOWN_ARROW:
                    if(hiss.getDir() != UP){
                        hiss.setDir(DOWN);
                    }
                    break;
                case LEFT_ARROW:
                    if(hiss.getDir() != RIGHT){
                        hiss.setDir(LEFT);
                    }
                    break;
                case RIGHT_ARROW:
                    if(hiss.getDir() != LEFT){
                        hiss.setDir(RIGHT);
                    }
                    break;
                case SPACE:
                    if(fun.checkState() == PLAY){
                        fun.changeState(PAUSE);
                    }
                    else if(fun.checkState() == PAUSE){
                        fun.changeState(PLAY);
                    }
                    break;
                case P:
                    fun.changeState(PLAY);
                    break;
            }
        }

        if(fun.checkState() == START){
            for(int y = 0; y < NUM_ROW + SIZE; y++){
                for(int x = 0; x > NUM_COL; x++){
                    g.plotPixel(x, y, 255, 255, 255);
                }
            }
        }
        else if(fun.checkState() == PLAY || fun.checkState() == PAUSE){
        // Check states
            if(fun.checkState() == PLAY){
                // Advance
                hiss.advance();
            }

            // die check
            fun.changeState(hiss.checkDie(soundEffects, g));

        // Fruit
            if(hiss.getFirstPt().x == apple.getPoint().x &&
               hiss.getFirstPt().y == apple.getPoint().y){
                //apple.setPoint((((rand()% (1000 / SIZE -1 )) +1) * SIZE) ,
                //               (((rand()% (1000 / SIZE -1 )) +1) * SIZE));
                apple.eatenFruit();
                hiss.incLength(1);
                fun.addPoint();
                soundEffects.eating(g);
            }

        // Draw
            // Draw background
            for(int y = 0; y < NUM_ROW; y++){
                for(int x = 0; x < NUM_COL; x++){
                    if(y%SIZE == 0 || x%SIZE == 0){
                        g.plotPixel(x, y,20,250,20);
                    }
                    else{
                        g.plotPixel(x, y,0,0,0);
                    }
                }
            }

            // Draw Fruit
            apple.drawFriut(apple.getPoint() , g);

            // Draw Snake
            hiss.draw(g);


        }
        else if(fun.checkState() == OVER){
            for(int y = 0; y < NUM_ROW + SIZE; y++){
                for(int x = 0; x < NUM_COL; x++){
                    g.plotPixel(x, y, 250, 20, 20);
                }
            }

        }


        g.update();
        g.Sleep(SPEED);


    }
    return 0;
}
