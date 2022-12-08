/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef scoreboard_h
#define scoreboard_h
#include "font.h"


class Scoreboard{
private:
    int highScore;
    font ffont;
public:
    void saveToFile(ofstream&);
    void initialize(ifstream&);
    int getHighScore();
    void setHighScore(int);
    void printHighScore(SDL_Plotter&, font&);
};

#endif /* scoreboard_h */
