#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDl_PLotter.h"
#include "point.h"
#include "constants.h"
#include "sound.h"

class snake{
private:
    int length;
    Direction dir;
    color cBody, cHead;

    Point_t loc[MAX];

public:
    snake(int l, color c = color(112, 112, 112)){
        length = l;
        cBody = c;

        for(int i = 0; i < MAX; i++){
            loc[i] = Point_t(-SIZE, -SIZE);
        }

        for(int i = 0; i < length; i++){
            loc[i] = Point_t(NUM_ROW / 2 - i*SIZE,
                             NUM_COL / 2 - i*SIZE);
        }
    }

    void setColorBody(color c = color(112, 112, 112)){
        cBody = c;
    }
    void setColorHead(color c = color(255, 153, 0)){
        cHead = c;
    }
    void setDir(Direction d){
        dir = d;
    }
    void setLength(int l){
        length = l;
    }

    Point_t getFirstPt(void){
        return loc[0];
    }
    color getColorBody(void){
        return cBody;
    }
    color getColorHead(void){
        return cHead;
    }
    Direction getDir(void){
        return dir;
    }
    int getLength(void){
        return length;
    }

    void incLength(int n){
        length += n;
    }

    GameState checkDie(Sound& soundEffects, SDL_Plotter& g){
        GameState retVal = PLAY;
        for(int i = 1; i < length; i++){
            if(loc[0].x == loc[i].x && loc[0].y == loc[i].y){
                retVal = OVER;
            }
        }
        if(loc[0].x == -SIZE || loc[0].x == NUM_COL){
            retVal = OVER;
        }
        if(loc[0].y == -SIZE || loc[0].y == NUM_ROW){
            retVal = OVER;
        }
        if(retVal == OVER){
            soundEffects.dying(g);
        }
        return retVal;
    }

    void advance(){
        for(int i = length - 1; i > 0; i--){
            loc[i] = loc[i-1];
        }
        switch(dir){
            case UP:
                    loc[0].y -= SIZE;
                    break;

            case DOWN:
                    loc[0].y += SIZE;
                    break;

            case LEFT:
                    loc[0].x -= SIZE;
                    break;

            case RIGHT:
                    loc[0].x += SIZE;
                    break;
        }

    }

    void draw(SDL_Plotter& g){
        for(int i = 0; i < length; i++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){

                    if(i == 0){
                        g.plotPixel(loc[i].x + x, loc[i].y + y, cHead);
                    }
                    else{
                        g.plotPixel(loc[i].x + x, loc[i].y + y, cBody);
                    }
                }
            }
        }
    }
};

#endif // SNAKE_H_INCLUDED
