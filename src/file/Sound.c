#include "file/Sound.h"


void initSounds() {
	// Import Library 
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) { //Initialize API Mixer
        printf("%s", Mix_GetError());
   }
}

void loadMusics() {
    //loads the differents sound files on memory 
    Mix_AllocateChannels(32); //Allouer 32 canaux, mais on en a pas tous besoin
    sounds[0] = Mix_LoadWAV("sounds/game.wav"); 
    sounds[1] = Mix_LoadWAV("sounds/destroy.wav");
}

void playMusic(int canal, int musique, float volume) {

    if (canal == SFXCANAL) {
        currCanal ++;
        if (currCanal > 31) currCanal = 1;
        canal = currCanal;
    }

    Mix_VolumeChunk(sounds[musique], MAXVOLUME * volume);
    Mix_PlayChannel(canal,sounds[musique], 0);
    

}

void muteMusic(){
    if (mute==1)
    {
        Mix_Pause(-1);
    }
    else {
        Mix_Resume(-1);
    }                
}