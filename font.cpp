

#include "font.h"


void font::printFont(string fileName, int yBaseLocation , int xBaseLocation, SDL_Plotter& g){
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
            for(int y = yBaseLocation; y < yBaseLocation + 5; y++){
                for(int x = xBaseLocation; x < xBaseLocation + 5; x++){
                    g.plotPixel(x + space, y + row, 255, 255, 255);
                }
            }
        }
        if(k % 24 == 0){
            row += 5;
            space = 0;
        }
        space += 5;
    }
    iFile.close();
}

void font::printFontLetter(string fileName, int yBaseLocation , int xBaseLocation, SDL_Plotter& g){
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
            for(int y = yBaseLocation; y < yBaseLocation + 1; y++){
                for(int x = xBaseLocation; x < xBaseLocation + 1; x++){
                    g.plotPixel(x + space, y + row, 255, 255, 255);
                }
            }
        }
        if(k % 49 == 0){
            row += 1;
            space = 0;
        }
        space += 1;
    }
    iFile.close();
}


