/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#include "sound.h"

void Sound::dying(SDL_Plotter& g){
    g.playSound(dyingSoundFileName);
}

void Sound::eating(SDL_Plotter& g){
    g.playSound(eatingSoundFileName);
}
