/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */
#include "font.h"

void font::printFontNumber(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int R, int G, int B){
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

void font::printScoreSingle(int score, font& text, SDL_Plotter& g, int x, int y, int thickness){
    stringstream ss;
    ss << score;
    string name = ss.str();
    text.printFontNumber(name + ".txt", x, y, g, thickness, 0, 0, 0);
    ss.flush();
}


void font::printScoreDouble(int score, font& text, SDL_Plotter& g, int x1, int y1, int x2, int y2, int thickness){
    stringstream ss;
    ss << score;
    string number = ss.str();
    char first = number.at(0);
    char second = number.at(1);
    string fname = "";
    string fname1 = "";
    fname = fname + first;
    fname.append(".txt");
    fname1 = fname1 + second;
    fname1.append(".txt");
    text.printFontNumber(fname, x1, y1, g, thickness, 0, 0, 0);
    text.printFontNumber(fname1, x2, y2, g, thickness, 0, 0, 0);
    ss.flush();
}

void font::printScoreTriple(int score, font& text, SDL_Plotter& g, int x1, int y1, int x2, int y2, int x3, int y3, int thickness){
    stringstream ss;;
    ss << score;
    string number = ss.str();
    char first = number.at(0);
    char second = number.at(1);
    char third = number.at(2);
    string fname = "";
    string fname1 = "";
    string fname2 = "";
    fname = fname + first;
    fname.append(".txt");
    fname1 = fname1 + second;
    fname1.append(".txt");
    fname2 = fname2 + third;
    fname2.append(".txt");
    text.printFontNumber(fname, x1, y1, g, thickness, 0, 0, 0);
    text.printFontNumber(fname1, x2, y2, g, thickness, 0, 0, 0);
    text.printFontNumber(fname2, x3, y3, g, thickness, 0, 0, 0);
    ss.flush();
}

