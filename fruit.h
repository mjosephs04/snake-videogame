/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef fruit_h
#define fruit_h
#include "SDL_Plotter.h"
#include "point.h"
#include "constants.h"
#include "snake.h"


class Fruit{
private:
    Point_t p;
public:
    Fruit(){
        p.x = rand() %NUM_ROW;
        p.y = rand() %NUM_COL;
    }

    void draw(SDL_Plotter&);

    Point_t getPoint() const;

    void setPoint(int, int);

    void eatenFruit(snake);

    void initialize(ifstream& fin);
    void saveToFile(ofstream& fout);


};

#endif /* fruit_h */
