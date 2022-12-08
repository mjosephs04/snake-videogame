/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef SOUND_H_
#define SOUND_H_

#include "SDL_Plotter.h"
#include <string>
using namespace std;


class Sound{
private:
    string dyingSoundFileName = "dying-sound.wav";
    string eatingSoundFileName = "eating-apple.wav";

public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: Sound constructor                                         *
    * return: N/A                                                            *
    * precondition: SDL Plotter exists, there is a dying sound and eating    *
    *               apple sound file                                         *
    * postcondition: sound object exists and the files are initialized       *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Sound(SDL_Plotter& g){
        g.initSound(dyingSoundFileName);
        g.initSound(eatingSoundFileName);
    }
    
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: plays dying sound                                         *
    * return: void                                                           *
    * precondition: SDL_Plotter exists, Sound object exists and is           *
    *               initialized                                              *
    * postcondition: nothing is changed, sound is played                     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void dying(SDL_Plotter&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: plays eating sound                                        *
    * return: void                                                           *
    * precondition: SDL_Plotter exists, Sound object exists and is           *
    *               initialized                                              *
    * postcondition: nothing is changed, sound is played                     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void eating(SDL_Plotter&);

};

#endif // SOUND_H_
