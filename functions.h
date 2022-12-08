/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef functions_h
#define functions_h
#include "SDL_Plotter.h"
#include "font.h"
#include "constants.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: plots the background to the Plotter                           *
* return: void                                                               *
* precondition: SDL_Plotter exists                                           * 
* postcondition: background is plotted                                       *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void plotBackground(SDL_Plotter&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: prints instructions for how to save progress                  *
* return: void                                                               *
* precondition: SDL plotter and font object exist                            *
* postcondition: save instructions are printed in the corner or potter       *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printEscSave(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: prints instructions for pause to the screen                   *
* return: void                                                               *
* precondition: SDL_plotter and font object exist                            *
* postcondition: pause instructions are printed to the screen                *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printPause(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: Game Over is printed to the screen                            *
* return: void                                                               *
* precondition: SDL_Plotter and font object exist                            *
* postcondition: Game Over is printed to plotter                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printGameOver(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: Score is printed to screen                                    *
* return: void                                                               *
* precondition: SDL_Plotter and font object exist                            *
* postcondition: score is printed to screen                                  *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printYourScore(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: the word score is printed to screen                           *
* return: void                                                               *
* precondition: SDL_Plotter and font object exist                            *
* postcondition: the word score is printed to screen                         *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printScoreText(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: Instructions to start game are printed to screen              *
* return: void                                                               *
* precondition: SDL_Plotter and font object exist                            *
* postcondition: start instructions are printed                              *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printPressStart(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: restart instructions are printed to screen                    *
* return: void                                                               *
* precondition: SDL_Plotter and text object exist                            *
* postcondition: restart instructions are printed                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printRestart(SDL_Plotter& g, font& text);


#endif /* functions_h */
