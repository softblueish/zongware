#ifndef GAME_HPP
#define GAME_HPP
#endif
#ifndef GRAPHICS_HPP
#include <zongware/graphics.hpp>
#endif
#ifndef INPUT_HPP
#include <zongware/input.hpp>
#endif
#ifndef ENTITY_HPP
#include <zongware/entity.hpp>
#endif
#ifndef AUDIO_HPP
#include <zongware/audio.hpp>
#endif
#ifndef THREADS_HPP
#include <zongware/threads.hpp>
#endif
#ifndef STANDARD_HPP
#include <zongware/standard.hpp>
#endif
#include <thread>
#include <iostream>


void start(std::vector<Entity*> *stack);

void loop(std::vector<Entity*> *stack);