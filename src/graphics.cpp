#ifndef GRAPHICS_HPP
#include <zongware/graphics.hpp>
#endif
#ifndef AUDIO_HPP
#include <zongware/audio.hpp>
#endif
#ifndef THREADS_HPP
#include <zongware/threads.hpp>
#endif
#ifndef ENTITY_HPP
#include <zongware/entity.hpp>
#endif

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Rect rect;

int windowSize[2] = {640, 480};
std::string title = "Game";
int framerate = 60;
bool vsync = true;

int mouseX, mouseY;
int mousedX, mousedY;
int mouseState;

mouse getMouse(){
    mouse m = {mouseX, mouseY, mousedX, mousedY, mouseState};
    return m;
}

bool Entity::mouseIsPressing(){
    int mouseX, mouseY;
    if(SDL_GetMouseState(&mouseX, &mouseY)!=1) return false;
    return mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h;
}

bool Entity::mouseIsHovering(){
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h;
}

void setWindowSize(int width, int height){
    windowSize[0] = width;
    windowSize[1] = height;
}

void setTitle(std::string t){
    title = t;
}

void setFramerate(int f){
    framerate = f;
}

void setVsync(bool v){
    vsync = v;
}

void startGraphics(){
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize[0], windowSize[1], SDL_WINDOW_SHOWN);
    if(vsync) renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
    else renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void restartGraphics(){
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    startGraphics();
}

SDL_Texture* createDefaultTexture(SDL_Surface* surface){
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
}

void renderGraphics(std::vector<Entity*> *stack){
    int maxLayers = 0;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    while(isStackInUse());
    setStackInUse(true);
    SDL_GetMouseState(&mouseX, &mouseY);
    mouseState = SDL_GetRelativeMouseState(&mousedX, &mousedY);
    for(int entityID = 0; entityID < stack->size(); entityID++) {
        if(stack->at(entityID)->layer > maxLayers) {
            maxLayers = stack->at(entityID)->layer;
        }
    }
    for(int layer = maxLayers; layer > -1; layer--){
        for(int entityID = 0; entityID < stack->size(); entityID++){
            if(!stack->at(entityID)->visible) continue;
            if(stack->at(entityID)->layer != layer) continue;
            switch(stack->at(entityID)->type){
                case 's':
                    {   
                        rect = {stack->at(entityID)->x, stack->at(entityID)->y, stack->at(entityID)->w, stack->at(entityID)->h};
                        SDL_RenderCopyEx(renderer, stack->at(entityID)->texture, NULL, &rect, stack->at(entityID)->rotation % 360, NULL, stack->at(entityID)->mirrored ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
                    }
                    break;
                case 'r':
                    {
                        rect = {stack->at(entityID)->x, stack->at(entityID)->y, stack->at(entityID)->w, stack->at(entityID)->h};
                        SDL_SetRenderDrawColor(renderer, stack->at(entityID)->color[0], stack->at(entityID)->color[1], stack->at(entityID)->color[2], stack->at(entityID)->color[3]);
                        SDL_RenderFillRect(renderer, &rect);
                    }
                    break;
                case 'c':
                    {
                        filledCircleRGBA(renderer, stack->at(entityID)->x, stack->at(entityID)->y, stack->at(entityID)->w, stack->at(entityID)->color[0], stack->at(entityID)->color[1], stack->at(entityID)->color[2], stack->at(entityID)->color[3]);
                    }
                    break;
            }
        }
    }
    setStackInUse(false);
    SDL_RenderPresent(renderer);
    if(framerate>0) SDL_Delay(1000 / framerate);
}

void endGraphics(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();
}
