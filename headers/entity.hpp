#ifndef ENTITY_HPP
#define ENTITY_HPP
#endif
#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

class Entity{
    public:
        int id; // Position in the stack
        std::string identifier; // Identifier for the entity
        char type; // s = sprite, r = rectangle, c = circle
        int x, y, w, h; // x, y, width, height
        bool visible = true; // visible or not
        std::string sourcePath; // path to texture
        SDL_Surface* surface;
        int color[4]; // color for rectangle or circle

        Entity(std::string identifier, char type, int x, int y, int w, int h, std::string sourcePath){
            this->identifier = identifier;
            this->type = type;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->sourcePath = sourcePath;
        }
        Entity(std::string identifier, char type, int x, int y, int w, int h){
            this->identifier = identifier;
            this->type = type;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
        }

        void load(std::vector<Entity*> *stack);
        void unload(std::vector<Entity*> *stack);
        void free();
};