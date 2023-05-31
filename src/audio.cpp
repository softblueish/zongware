#ifndef AUDIO_HPP
#include <zongware/audio.hpp>
#endif

std::vector<Mix_Music*> music;
std::vector<Mix_Chunk*> sfx;

int loadMusic(std::string wav){
    int id = music.size();
    Mix_Music *newMusic = Mix_LoadMUS(wav.c_str());
    music.push_back(newMusic);
    if(music.at(id)==NULL) std::cout << "Failed to load " << wav << "! (" << id << ")" << std::endl;
    return id;
}

int loadSFX(std::string wav){
    int id = sfx.size();
    Mix_Chunk *newSFX = Mix_LoadWAV(wav.c_str());
    sfx.push_back(newSFX);
    if(sfx.at(id)==NULL) std::cout << "Failed to load " << wav << "! (" << id << ")" << std::endl;
    return id;
}

void unloadMusic(int id){
    Mix_FreeMusic(music.at(id));
    music.erase(music.begin() + id);
}

void unloadSFX(int id){
    Mix_FreeChunk(sfx.at(id));
    sfx.erase(sfx.begin() + id);
}

void playMusic(int id){
    Mix_PlayMusic(music.at(id), -1);
}

void playSFX(int id){
    Mix_PlayChannel(-1, sfx.at(id), 0);
}

void stopMusic(){
    Mix_HaltMusic();
}

void stopSFX(){
    Mix_HaltChannel(-1);
}