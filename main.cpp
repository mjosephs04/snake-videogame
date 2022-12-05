#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include "SDL_Plotter.h"
#include "gameObject.h"
#include "sound.h"
#include <ctime>

using namespace std;


enum Direction {UP, DOWN, LEFT, RIGHT};

int main(int argc, char* argv[]) {

    char key;
    int length = 3;
    SDL_Plotter g(NUM_ROW + 50, NUM_COL);
    int xLoc[NUM_COL], yLoc[NUM_ROW];
    Direction dir = RIGHT;
    int speed = 70;
    Game fun;
    bool isPaused;
    int score = 0;


    for(int i = 0; i < NUM_COL; i++){
        xLoc[i] = -2;
    }
    for(int i = 0; i < NUM_ROW; i++){
        yLoc[i] = -2;
    }

    xLoc[0] = NUM_COL / 2;
    xLoc[1] = NUM_COL / 2 - SIZE;
    yLoc[0] = NUM_ROW / 2;
    yLoc[1] = NUM_ROW / 2;
    Fruit apple;
    Sound soundEffects(g);


    //vector<Point_t> snake;
    //Point_t newSection;

    srand(time(0));

    apple.setPoint((((rand()%(NUM_COL / SIZE) )) * SIZE) , (rand()%(NUM_ROW / SIZE) * SIZE));
    while(!g.getQuit()){


       if(g.kbhit()){
            key = g.getKey();
           switch(key){
               case UP_ARROW     : if(dir != 1){dir = UP;};
                                    break;

               case DOWN_ARROW   : if(dir != 0){dir = DOWN;};
                                    break;

               case LEFT_ARROW   : if(dir != 3){dir = LEFT;};
                                    break;

               case RIGHT_ARROW  : if(dir != 2){dir = RIGHT;};
                                    break;

               case SPACE        : if(!isPaused){isPaused = true;}
                                   else{isPaused = false;}
                                    break;

           }
        }

    //process
    if(!isPaused){
        if(fun.checkState() != OVER){
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

            //copy cell locations
            for(int i = length - 1; i > 0; i--){
                xLoc[i] = xLoc[i-1];
                yLoc[i] = yLoc[i-1];
            }
            switch(dir){
                case RIGHT : xLoc[0] += SIZE;
                    break;

                case LEFT  : xLoc[0] -= SIZE;
                    break;

                case UP    : yLoc[0] -= SIZE;
                    break;

                case DOWN  : yLoc[0] += SIZE;
                    break;
            }

            //game check
            if(xLoc[0] == -SIZE || xLoc[0] == NUM_COL){
                fun.changeState(OVER);
                soundEffects.dying(g);
            }
            if(yLoc[0] == -SIZE || yLoc[0] == NUM_ROW){
                fun.changeState(OVER);
                soundEffects.dying(g);
            }

            //hit detection of itself
            for(int i = 1; i < length; i++){
                if(xLoc[0] == xLoc[i] && yLoc[0] == yLoc[i]){
                    fun.changeState(OVER);
                    soundEffects.dying(g);
                }
            }

            //Draw
            for(int i =0; i < length; i++){
                for(int y = 0; y < SIZE; y++){
                    for(int x = 0; x < SIZE; x++){
                        if(i == 0){
                            g.plotPixel(xLoc[i] + x, yLoc[i] + y, 255, 153, 0);

                        }
                        else{
                            g.plotPixel(xLoc[i] + x, yLoc[i] + y, 112, 112, 112);
                        }
                    }
                }

            }

            //check if it hits apple
            if(xLoc[0] == apple.getPoint().x && (yLoc[0] == apple.getPoint().y)){
                apple.setPoint((((rand()% (NUM_COL / SIZE -1 )) +1) * SIZE) , (((rand()% (NUM_ROW / SIZE -1 )) +1) * SIZE));
                apple.eatenFruit();
                length++;
                fun.addPoint();
                cout << "score: " << fun.getScore() << endl;
                soundEffects.eating(g);

            }

            apple.drawFriut(apple.getPoint(), g);

        }
        else{
            for(int y = 0; y < NUM_ROW + 50; y++){
                for(int x = 0; x < NUM_COL; x++){
                    g.plotPixel(x, y, 250, 20, 20);
                }
            }
        }
    }
    else{
        //if is paused, show black screen
        for(int y = 0; y < NUM_ROW; y++){
            for(int x = 0; x < NUM_COL; x++){
                g.plotPixel(x, y,0,0,0);
            }
        }
    }
    //draw  background


    g.update();
    g.Sleep(speed);      //takes miliseconds for its argument

    }
    return 0;
}

