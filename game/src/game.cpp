#ifndef GAME_HPP
#include "../../headers/game.hpp"
#endif

Entity zong(0, 0, 200, 200, "zong.bmp");
Entity cat(50, 50, 200, 200, "cat.bmp");

void start(std::vector<Entity*> *stack){
    zong.setLayer(1);
    cat.setLayer(0);
    cat.load(stack);
    zong.load(stack);
}

void loop(std::vector<Entity*> *stack){
     
}