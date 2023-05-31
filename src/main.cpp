#ifndef GAME_HPP
#include "../headers/game.hpp"
#endif
#ifndef THREADS_HPP
#include "../headers/threads.hpp"
#endif

std::vector<Entity*> stack;
bool allocatedThreadInUse;

void gameloop(){
    while(true){
        loop(&stack);
    }
}

int main(){
    startGraphics();
    
    start(&stack);

    std::thread gameloopThread = std::thread(gameloop);
    gameloopThread.detach();

    while(true){
        if(shouldClose() || didGameExit()) break;
        renderGraphics(&stack);
    }

    gameloopThread.~thread();
    endGraphics();
}

