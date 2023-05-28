#ifndef GAME_HPP
#include "../headers/game.hpp"
#endif

std::vector<Entity*> stack;

int main(){
    startGraphics();
    
    start(&stack);

    while(true){
        if(shouldClose() || checkInput(SDLK_ESCAPE)) break;

        loop(&stack);

        renderGraphics(&stack);
    }
    endGraphics();
}