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


class scoreboard{
private:
    int highScore;
    font ffont;
public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: saves position of snake to a file                         *
    * return: void                                                           *
    * precondition: output stream                                            *
    * postcondition: saves position to a file                                *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void saveToFile(ofstream&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: initializes the scoreboard                                *
    * return: void                                                           *
    * precondition: input stream                                             *
    * postcondition: scoreboard is initialized                               *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void initialize(ifstream&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: getting the high score                                    *
    * return: integer                                                        *
    * precondition: there is a score                                         *
    * postcondition: returns the highscore of the user                       *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int getHighScore();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: highscore is set for program                              *
    * return: void                                                           *
    * precondition: an integer                                               *
    * postcondition: the highscore is set                                    *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void setHighScore(int);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: prints the highscore on the plotter                       *
    * return: void                                                           *
    * precondition: sdl plotter and a font class                             *
    * postcondition: the highscore is plotted on the screen                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printHighScore(SDL_Plotter&, font&);
};

#endif /* scoreboard_h */
