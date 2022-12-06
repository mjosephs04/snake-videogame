#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <string>
#include <fstream>
#include "SDL_Plotter.h"

using namespace std;

class font{
private:
    int number;
    //int zero[264];
    //int letter[1274];

public:
    void printFont(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int R, int G, int B);
    void printFontLetter(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int, int, int);

};

#endif // FONT_H_INCLUDED
