#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#endif
#ifndef ENTITY_HPP
#include "../headers/entity.hpp"
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void startGraphics(const char* title);

void restartGraphics(const char* title);

void renderGraphics(std::vector<Entity*> *stack);

void endGraphics();