//
//  fruit.h
//  SDL Practice
//
//  Created by Caleb Beckering on 11/16/22.
//

#ifndef fruit_h
#define fruit_h
#include "constants.h"
#include "point.h"
#include "SDL_Plotter.h"
#include <SDL2/SDL.h>
#include <fstream>

class Fruit{
private:
    Point_t p;
public:
    Fruit(){
        p.x = rand() %NUM_ROW;
        p.y = rand() %NUM_COL;
    }

    void drawFriut(const Point_t&, SDL_Plotter&);

    Point_t getPoint() const;

    void setPoint(int, int);

    void eatenFruit();

    void initialize(ifstream& fin);
    void saveToFile(ofstream& fout);


};

#endif /* fruit_h */
