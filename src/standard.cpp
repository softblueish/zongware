#ifndef STANDARD_HPP
#include "../headers/standard.hpp"
#endif
#ifndef GAME_HPP
#include "../headers/game.hpp"
#endif

void delay(int ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}