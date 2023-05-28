#ifndef GRAPHICS_HPP
#include "../headers/graphics.hpp"
#endif
#ifndef PROPERTIES_HPP
#include "../game/headers/properties.hpp"
#endif
SDL_Window* window;
SDL_Renderer* renderer;

SDL_Rect rect;

void startGraphics(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize[0], windowSize[1], SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void restartGraphics(const char* title){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    startGraphics();
}

SDL_Texture* createTexture(SDL_Surface* surface) {
    return SDL_CreateTextureFromSurface(renderer, surface);
}

void renderGraphics(std::vector<Entity*> *stack){
    int maxLayers;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int entityID = 0; entityID < stack->size(); entityID++) if(stack->at(entityID)->layer>maxLayers) maxLayers = stack->at(entityID)->layer;
    for(int layer = maxLayers; layer > -1; layer--){
        for(int entityID = 0; entityID < stack->size(); entityID++){
            if(!stack->at(entityID)->visible) continue;
            if(stack->at(entityID)->layer != layer) continue;
            switch(stack->at(entityID)->type){
                case 's':
                    {   
                        if(stack->at(entityID)->surface == NULL) std::cout << "Failed to create texture from surface, there is no texture! (" << stack->at(entityID) << ")" << std::endl;
                        rect = {stack->at(entityID)->x, stack->at(entityID)->y, stack->at(entityID)->w, stack->at(entityID)->h};
                        SDL_RenderCopy(renderer, stack->at(entityID)->texture, NULL, &rect);
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
                default:
                    break;
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1000 / framerate);
}

void endGraphics(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
