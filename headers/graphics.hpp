#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#endif
#ifndef ENTITY_HPP
#include "../headers/entity.hpp"
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void startGraphics();

void restartGraphics();

SDL_Texture* createDefaultTexture(SDL_Surface* surface);

void renderGraphics(std::vector<Entity*> *stack);

void endGraphics();