/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#include "scoreboard.h"
#include "constants.h"
#include "font.h"

void scoreboard::saveToFile(ofstream& fout){
    fout << "High Score: " << highScore << endl;
}
void scoreboard::initialize(ifstream& fin){
    string temp;
    getline(fin, temp ,':');
    fin >> highScore;
}
int scoreboard::getHighScore(){
    return highScore;
}

void scoreboard::setHighScore(int score){
    highScore = score;
}

void scoreboard::printHighScore(SDL_Plotter& g, font& text){

    ffont.printFontLetter("h.txt", 75, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("i.txt", 150, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("g.txt", 225, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("h.txt", 300, 600, g, 2, 0, 0, 0);

    ffont.printFontLetter("s.txt", 425, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("c.txt", 500, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("o.txt", 575, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("r.txt", 650, 600, g, 2, 0, 0, 0);
    ffont.printFontLetter("e.txt", 725, 600, g, 2, 0, 0, 0);

    if(highScore < 10){
        text.printScoreSingle(highScore, text, g, 850, 595, 5);
    }
    else if(highScore < 100){
        text.printScoreDouble(highScore, text, g, 810, 595, 875, 595, 5);
    }
    else{
        text.printScoreTriple(highScore, text, g,
                              810, 600, 860, 600, 910, 600, 4);
    }

}
