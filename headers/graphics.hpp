#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#endif
#ifndef ENTITY_HPP
#include <zongware/entity.hpp>
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

struct mouse{
    int x, y;
    int dx, dy;
    int state;
};

mouse getMouse();

void setWindowSize(int width, int height);

void setTitle(std::string t);

void setFramerate(int f);

void setVsync(bool v);

void startGraphics();

void restartGraphics();

SDL_Texture* createDefaultTexture(SDL_Surface* surface);

void renderGraphics(std::vector<Entity*> *stack);

void endGraphics();