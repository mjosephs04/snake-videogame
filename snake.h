#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDl_PLotter.h"
#include "point.h"

class snake{
private:
    int length;
    Direction dir;
    color c;

    Point_t loc[MAX];

public:
    snake(int l){
        length = l;

        for(int i = 0; i < MAX; i++){
            loc[i] = Point_t(-2, -2);
        }

        for(int i = 0; i < length; i++){
            loc[i] = Point_t(NUM_ROW / 2 - i*SIZE,
                             NUM_COL / 2 - i*SIZE)
        }
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
                    (loc[i] + Point_t(x, y)).draw(g, c);
                }
            }
        }
    }
};

#endif // SNAKE_H_INCLUDED
