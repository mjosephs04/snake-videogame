#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDl_PLotter.h"
#include "point.h"
#include "constants.h"

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
            loc[i] = Point_t(-2, -2);
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

    void advance(){
        switch(dir){
            case UP:
                    loc[0] = loc[0] + Point_t(0, SIZE);
                    break;

            case DOWN:
                    loc[0] = loc[0] - Point_t(0, SIZE);
                    break;

            case LEFT:
                    loc[0] = loc[0] - Point_t(SIZE, 0);
                    break;

            case RIGHT:
                    loc[0] = loc[0] + Point_t(SIZE, 0);
                    break;
        }

        for(int i = length - 1; i > 0; i--){
            loc[i] = loc[i-1];
        }
    }

    void draw(SDL_Plotter& g){
        for(int i = 0; i < length; i++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){

                    if(i == 0){
                        (loc[i] + Point_t(x, y)).draw(g, cHead);
                    }
                    else{
                        (loc[i] + Point_t(x, y)).draw(g, cBody);
                    }
                }
            }
        }
    }
};

#endif // SNAKE_H_INCLUDED
