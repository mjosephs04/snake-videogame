#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include "SDL_Plotter.h"
#include "fruit.h"
using namespace std;

const int NUM_ROW = 1000;
const int NUM_COL = 1000;



enum Direction {UP, DOWN, LEFT, RIGHT};

int main(int argc, const char * argv[]) {
    
    char key;
    int length = 10;
    SDL_Plotter g(NUM_ROW, NUM_COL);
    int R = 112, G = 112, B = 112;
    //int xLoc = NUM_COL / 2, yLoc = NUM_ROW / 2;
    int xLoc[length], yLoc[length];
    int prevX, prevY;
    Direction dir = RIGHT;
    int speed = 100;
    int skip = 0, skip_val = 10;
    xLoc[0] = NUM_COL / 2;
    xLoc[1] = NUM_COL / 2 - 25;
    yLoc[0] = NUM_ROW / 2;
    yLoc[1] = NUM_ROW / 2;
    Fruit apple;
    
    srand(time(0));
    
    apple.setPoint((((rand()% (1000 / SIZE)) +1) * SIZE) , (((rand()% (1000 / SIZE)) +1) * SIZE));
    while(!g.getQuit()){
    
    
       if(g.kbhit()){
            key = g.getKey();
           switch(key){
               case UP_ARROW     : dir = UP;
                                    break;
                   
               case DOWN_ARROW   : dir = DOWN;
                                    break;
                   
               case LEFT_ARROW   : dir = LEFT;
                                    break;
                   
               case RIGHT_ARROW  : dir = RIGHT;
                                    break;
                   
           }
        }
    
    //process
        
    //draw black background
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
    //draw background
        
    
    
    //Draw
    for(int i =0; i < length; i++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){
                if(i == 0){
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, 255, 153, 0);
                }
                else{
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, R, G, B);
                }
            }
        }
    }
       
        if(xLoc[0] == apple.getPoint().x && (yLoc[0] == apple.getPoint().y)){
            apple.setPoint((((rand()% (1000 / SIZE -1 )) +1) * SIZE) , (((rand()% (1000 / SIZE -1 )) +1) * SIZE));
            length++;
        }
        
        apple.drawFriut(apple.getPoint() , g);
    g.update();
    g.Sleep(speed);      //takes miliseconds for its argument
    
    }
    return 0;
}

