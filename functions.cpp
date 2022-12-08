//
//  functions.cpp
//  groupProject(final)
//
//  Created by Caleb Beckering on 12/7/22.
//

#include "functions.h"

void printEscSave(SDL_Plotter& g, font& text){

    text.printFontLetter("s.txt", 650, 710, g, 1, 0, 0, 0);
    text.printFontLetter("a.txt", 690, 710, g, 1, 0, 0, 0);
    text.printFontLetter("v.txt", 740, 710, g, 1, 0, 0, 0);
    text.printFontLetter("e.txt", 780, 710, g, 1, 0, 0, 0);
    text.printFontLetter("quote.txt", 820, 700, g, 1, 0, 0, 0);
    text.printFontLetter("e.txt", 840, 710, g, 1, 0, 0, 0);
    text.printFontLetter("s.txt", 880, 710, g, 1, 0, 0, 0);
    text.printFontLetter("c.txt", 920, 710, g, 1, 0, 0, 0);
    text.printFontLetter("quote.txt", 950, 700, g, 1, 0, 0, 0);
}


void printPause(SDL_Plotter& g, font& text){
    text.printFontLetter("p.txt", 380, 710, g, 1, 0, 0, 0);
    text.printFontLetter("a.txt", 420, 710, g, 1, 0, 0, 0);
    text.printFontLetter("u.txt", 460, 710, g, 1, 0, 0, 0);
    text.printFontLetter("s.txt", 500, 710, g, 1, 0, 0, 0);
    text.printFontLetter("e.txt", 540, 710, g, 1, 0, 0, 0);
    text.printFontLetter("quote.txt", 570, 700, g, 1, 0, 0, 0);
    text.printFontLetter("quote.txt", 600, 700, g, 1, 0, 0, 0);
}

void printGameOver(SDL_Plotter& g, font& text){
    text.printFontLetter("g.txt", 100, 150, g, 5, 0, 0, 0);
    text.printFontLetter("a.txt", 300, 150, g, 5, 0, 0, 0);
    text.printFontLetter("m.txt", 500, 150, g, 5, 0, 0, 0);
    text.printFontLetter("e.txt", 700, 150, g, 5, 0, 0, 0);
    //new line
    text.printFontLetter("o.txt", 100, 300, g, 5, 0, 0, 0);
    text.printFontLetter("v.txt", 300, 300, g, 5, 0, 0, 0);
    text.printFontLetter("e.txt", 500, 300, g, 5, 0, 0, 0);
    text.printFontLetter("r.txt", 700, 300, g, 5, 0, 0, 0);
}


void printYourScore(SDL_Plotter& g, font& text){
    text.printFontLetter("y.txt", 75, 500, g, 2, 0, 0, 0);
    text.printFontLetter("o.txt", 150, 500, g, 2, 0, 0, 0);
    text.printFontLetter("u.txt", 225, 500, g, 2, 0, 0, 0);
    text.printFontLetter("r.txt", 300, 500, g, 2, 0, 0, 0);
    
    text.printFontLetter("s.txt", 425, 500, g, 2, 0, 0, 0);
    text.printFontLetter("c.txt", 500, 500, g, 2, 0, 0, 0);
    text.printFontLetter("o.txt", 575, 500, g, 2, 0, 0, 0);
    text.printFontLetter("r.txt", 650, 500, g, 2, 0, 0, 0);
    text.printFontLetter("e.txt", 725, 500, g, 2, 0, 0, 0);
}

void printScoreText(SDL_Plotter& g, font& text){
    text.printFontLetter("s.txt", 50, 710, g, 1, 0, 0, 0);
    text.printFontLetter("c.txt", 90, 710, g, 1, 0, 0, 0);
    text.printFontLetter("o.txt", 130, 710, g, 1, 0, 0, 0);
    text.printFontLetter("r.txt", 170, 710, g, 1, 0, 0, 0);
    text.printFontLetter("e.txt", 210, 710, g, 1, 0, 0, 0);
}

void printPressStart(SDL_Plotter& g, font& text){
    text.printFontLetter("P.txt", 190, 150, g, 3, 0, 0, 0);
    text.printFontLetter("r.txt", 310, 150, g, 3, 0, 0, 0);
    text.printFontLetter("e.txt", 430, 150, g, 3, 0, 0, 0);
    text.printFontLetter("s.txt", 550, 150, g, 3, 0, 0, 0);
    text.printFontLetter("s.txt", 670, 150, g, 3, 0, 0, 0);
    //newline
    text.printFontLetter("p.txt", 250, 250, g, 3, 0, 0, 0);
    text.printFontLetter("quote.txt", 230, 250, g, 1, 0, 0, 0);
    text.printFontLetter("t.txt", 490, 250, g, 3, 0, 0, 0);
    text.printFontLetter("quote.txt", 370, 250, g, 1, 0, 0, 0);
    text.printFontLetter("o.txt", 610, 250, g, 3, 0, 0, 0);
    //newline
    text.printFontLetter("s.txt", 190, 350, g, 3, 0, 0, 0);
    text.printFontLetter("t.txt", 310, 350, g, 3, 0, 0, 0);
    text.printFontLetter("a.txt", 430, 350, g, 3, 0, 0, 0);
    text.printFontLetter("r.txt", 550, 350, g, 3, 0, 0, 0);
    text.printFontLetter("t.txt", 670, 350, g, 3, 0, 0, 0);
}


void plotBackground(SDL_Plotter& g){
    for(int y = 0; y < NUM_ROW + SIZE; y++){
        for(int x = 0; x < NUM_COL; x++){
            g.plotPixel(x, y, 255, 255, 255);
        }
    }
}


void printRestart(SDL_Plotter& g, font& text){

    text.printFontLetter("r.txt", 290, 700, g, 1, 0, 0, 0);
    text.printFontLetter("e.txt", 330, 700, g, 1, 0, 0, 0);
    text.printFontLetter("s.txt", 370, 700, g, 1, 0, 0, 0);
    text.printFontLetter("t.txt", 410, 700, g, 1, 0, 0, 0);
    text.printFontLetter("a.txt", 450, 700, g, 1, 0, 0, 0);
    text.printFontLetter("r.txt", 490, 700, g, 1, 0, 0, 0);
    text.printFontLetter("t.txt", 530, 700, g, 1, 0, 0, 0);
    text.printFontLetter("quote.txt", 570, 690, g, 1, 0, 0, 0);
    text.printFontLetter("r.txt", 600, 700, g, 1, 0, 0, 0);
    text.printFontLetter("quote.txt", 630, 690, g, 1, 0, 0, 0);
}
