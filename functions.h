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

void plotBackground(SDL_Plotter&);

void printEscSave(SDL_Plotter&, font&);

void printPause(SDL_Plotter&, font&);

void printGameOver(SDL_Plotter&, font&);

void printYourScore(SDL_Plotter&, font&);

void printScoreText(SDL_Plotter&, font&);

void printPressStart(SDL_Plotter&, font&);

void printRestart(SDL_Plotter& g, font& text);


#endif /* functions_h */
