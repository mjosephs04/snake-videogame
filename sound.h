
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

    Sound(SDL_Plotter& g){
        g.initSound(dyingSoundFileName);
        g.initSound(eatingSoundFileName);
    }
    void dying(SDL_Plotter&);

    void eating(SDL_Plotter&);

};

#endif // SOUND_H_
