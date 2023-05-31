#ifndef STANDARD_HPP
#include <zongware/standard.hpp>
#endif
#ifndef GAME_HPP
#include <zongware/game.hpp>
#endif

void delay(int ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}