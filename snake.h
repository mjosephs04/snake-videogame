#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDl_PLotter.h"
#include "point.h"
#include "constants.h"
#include "sound.h"


class snake{
private:
    int length;
    Direction dir = UP;
    color cBody, cHead;

    Point_t loc[MAX];

public:
    snake(int l = 3);

    void setColorBody(color c = color(112, 112, 112));
    void setColorHead(color c = color(255, 153, 0));
    void setDir(Direction d);
    void setLength(int l);

    Point_t getFirstPt(void);
    Point_t getPoint(int);
    color getColorBody(void);
    color getColorHead(void);
    Direction getDir(void);
    int getLength(void);

    void incLength(int n);

    GameState checkDie(Sound&, SDL_Plotter&);

    void advance();

    void draw(SDL_Plotter& g);
    
    void initialize(ifstream&);
    
    void saveToFile(ofstream&);
};

#endif // SNAKE_H_INCLUDED
