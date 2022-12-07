#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <string>
#include <fstream>
#include "SDL_Plotter.h"
#include <sstream>
#include "font.h"

using namespace std;

class font{
private:
    int number;


public:
    void printFontNumber(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int R, int G, int B);
    void printFontLetter(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int, int, int);

    void printScoreSingle(int, font&, SDL_Plotter&, int, int, int = 3);
    void printScoreDouble(int, font&, SDL_Plotter&, int, int, int, int, int = 3);
    void printScoreTriple(int, font&, SDL_Plotter&, int, int, int, int, int, int, int = 3);

};

#endif // FONT_H_INCLUDED
