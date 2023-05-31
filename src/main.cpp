#ifndef GAME_HPP
#include <zongware/game.hpp>
#endif
#ifndef THREADS_HPP
#include <zongware/threads.hpp>
#endif

std::vector<Entity*> stack;
bool allocatedThreadInUse;

void gameloop(){
    while(true){
        loop(&stack);
    }
}

int main(){
    start(&stack);

    startGraphics();
    
    std::thread gameloopThread = std::thread(gameloop);
    gameloopThread.detach();

    while(true){
        if(shouldClose() || didGameExit()) break;
        renderGraphics(&stack);
    }

    gameloopThread.~thread();
    endGraphics();
}

