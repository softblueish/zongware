#ifndef ENTITY_HPP
#define ENTITY_HPP
#endif
#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

class Entity{
    public:
        unsigned int id; // Position in the stack
        unsigned int layer = 0; // Layer to render on
        char type; // s = sprite, r = rectangle, c = circle
        int x, y, w, h; // x, y, width, height
        bool visible = true; // visible or not
        std::string sourcePath; // path to texture
        SDL_Surface* surface;
        SDL_Texture* texture;
        int color[4]; // color for rectangle or circle

        // Constructors
        Entity(int x, int y, int width, int height, std::string sourcePath){
            this->type = 's';
            this->x = x;
            this->y = y;
            this->w = width;
            this->h = height;
            this->sourcePath = sourcePath;
        }

        Entity(int x, int y, int width, int height, int color[4]){
            this->type = 'r';
            this->x = x;
            this->y = y;
            this->w = width;
            this->h = height;
            for(int i = 0; i < 4; i++) this->color[i] = color[i];
        }

        Entity(int x, int y, int width, int height){
            this->type = 'r';
            this->x = x;
            this->y = y;
            this->w = width;
            this->h = height;
        }

        Entity(int x, int y, int radius){
            this->type = 'c';
            this->x = x;
            this->y = y;
            this->w = radius;
            this->h = 0;
        }

        Entity(int x, int y, int radius, int color[4]){
            this->type = 'c';
            this->x = x;
            this->y = y;
            this->w = radius;
            this->h = 0;
            for(int i = 0; i < 4; i++) this->color[i] = color[i];
        }

        // Sets variables
        void setLayer(unsigned int layer){
            this->layer = layer;
        }
        
        void setVisibility(bool visible){
            this->visible = visible;
        }
        
        void setSourcePath(std::string sourcePath){
            this->sourcePath = sourcePath;
        }
        
        void setColor(int color[4]){
            for(int i = 0; i < 4; i++) this->color[i] = color[i];
        }

        void setRadius(int radius){
            this->w = radius;
        }

        void load(std::vector<Entity*> *stack);
        void unload(std::vector<Entity*> *stack);
        void free();      
};