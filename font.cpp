#include "font.h"


void font::printFont(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int R, int G, int B){
    ifstream iFile;
    int zero[264];
    iFile.open(fileName);
    for(int x = 0; x < 264; x++){
        iFile >> number;
        zero[x] = number;
    }
    int space = 0;
    int row = 0;
    for(int k = 0; k < 264; k++){
        if(zero[k] == 1){
            for(int y = yBaseLocation; y < yBaseLocation + thickness; y++){
                for(int x = xBaseLocation; x < xBaseLocation + thickness; x++){
                    g.plotPixel(x + space, y + row, R, G, G);
                }
            }
        }
        if(k % 24 == 0){
            row += thickness;
            space = 0;
        }
        space += thickness;
    }
    iFile.close();
}

void font::printFontLetter(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int r, int G, int b){
    ifstream iFile;
    int letter[1274];
    iFile.open(fileName);
    for(int x = 0; x < 1274; x++){
        iFile >> number;
        letter[x] = number;
    }
    int space = 0;
    int row = 0;
    for(int k = 0; k < 1274; k++){
        if(letter[k] == 1){
            for(int y = yBaseLocation; y < yBaseLocation + thickness; y++){
                for(int x = xBaseLocation; x < xBaseLocation + thickness; x++){
                    g.plotPixel(x + space, y + row, r, G, b);
                }
            }
        }
        if(k % 49 == 0){
            row += thickness;
            space = 0;
        }
        space += thickness;
    }
    iFile.close();
}


