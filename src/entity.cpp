#ifndef ENTITY_HPP
#include "../headers/entity.hpp"
#endif

void Entity::load(std::vector<Entity*> *stack){
    id = stack->size();
    stack->push_back(this);
    surface = SDL_LoadBMP(sourcePath.c_str());
}

void Entity::unload(std::vector<Entity*> *stack){
    stack->erase(stack->begin() + id);
}

void Entity::free(){
    SDL_FreeSurface(surface);
}