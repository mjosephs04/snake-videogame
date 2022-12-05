
#include "sound.h"

void Sound::dying(SDL_Plotter& g){
    g.playSound(dyingSoundFileName);
}

void Sound::eating(SDL_Plotter& g){
    g.playSound(eatingSoundFileName);
}
