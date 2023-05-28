#ifndef INPUT_HPP
#include "../headers/input.hpp"
#endif

bool checkInput(SDL_Keycode key){
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if(state[SDL_GetScancodeFromKey(key)]){
        return true;
    }
    return false;
}

bool shouldClose(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            return true;
        }
    }
    return false;
}