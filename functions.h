//
//  functions.h
//  groupProject(final)
//
//  Created by Caleb Beckering on 12/7/22.
//

#ifndef functions_h
#define functions_h
#include "SDL_Plotter.h"
#include "font.h"
#include "constants.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void plotBackground(SDL_Plotter&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printEscSave(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printPause(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printGameOver(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printYourScore(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printScoreText(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printPressStart(SDL_Plotter&, font&);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* description: 
* return: void
* precondition:
* postcondition: 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printRestart(SDL_Plotter& g, font& text);


#endif /* functions_h */
