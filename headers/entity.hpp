#ifndef ENTITY_HPP
#define ENTITY_HPP
#endif
#ifndef THREADS_HPP
#include <zongware/threads.hpp>
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
        int rotation = 0; // rotation in degrees
        bool mirrored = false; // flipped or not
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

        // Checks
        bool mouseIsPressing();
        
        bool mouseIsHovering();

        // Sets variables
        void setLayer(unsigned int layer){
            while(isStackInUse());
            setStackInUse(true);
            this->layer = layer;
            setStackInUse(false);
        }
        
        void setVisibility(bool visible){
            while(isStackInUse());
            setStackInUse(true);
            this->visible = visible;
            setStackInUse(false);
        }
        
        void setSourcePath(std::string sourcePath){
            while(isStackInUse());
            setStackInUse(true);
            this->sourcePath = sourcePath;
            setStackInUse(false);
        }
        
        void setColor(int color[4]){
            while(isStackInUse());
            setStackInUse(true);
            for(int i = 0; i < 4; i++) this->color[i] = color[i];
            setStackInUse(false);
        }

        void setRadius(int radius){
            while(isStackInUse());
            setStackInUse(true);
            this->w = radius;
            setStackInUse(false);
        }

        void move(int x, int y){
            while(isStackInUse());
            setStackInUse(true);
            this->x += x;
            this->y += y;
            setStackInUse(false);
        }

        void rotate(int rotation){
            while(isStackInUse());
            setStackInUse(true);
            this->rotation += rotation;
            setStackInUse(false);
        }

        void flip(){
            while(isStackInUse());
            setStackInUse(true);
            this->mirrored = !this->mirrored;
            setStackInUse(false);
        }

        void load(std::vector<Entity*> *stack);
        void unload(std::vector<Entity*> *stack);
        void free();      
};