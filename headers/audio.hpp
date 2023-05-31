#ifndef AUDIO_HPP
#define AUDIO_HPP
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>

int loadMusic(std::string wav);

int loadSFX(std::string wav);

void unloadMusic(int id);

void unloadSFX(int id);

void playMusic(int id);

void playSFX(int id);

void stopMusic();

void stopSFX();