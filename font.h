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
    ifstream iFile;

public:
    void printFont(string fileName, int yBaseLocation , int xBaseLocation, SDL_Plotter&);
    void printFontLetter(string fileName, int yBaseLocation , int xBaseLocation, SDL_Plotter&);

};

#endif // FONT_H_INCLUDED
