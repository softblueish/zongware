#ifndef ENTITY_HPP
#include "../headers/entity.hpp"
#endif
#ifndef GRAPHICS_HPP
#include "../headers/graphics.hpp"
#endif

void Entity::load(std::vector<Entity*> *stack){
    id = stack->size();
    stack->push_back(this);
    if(surface!=NULL||sourcePath.empty()) return;
    surface = SDL_LoadBMP(sourcePath.c_str());
    if(surface==NULL){
        std::cout << "Failed to load " << sourcePath << "! (";
        std::cout << stack->at(id) << ")" << std::endl;
    }
    texture = createTexture(surface);
}

void Entity::unload(std::vector<Entity*> *stack){
    stack->erase(stack->begin() + id);
}

void Entity::free(){
    SDL_FreeSurface(surface); 
}