#ifndef ENTITY_HPP
#include "../headers/entity.hpp"
#endif
#ifndef GRAPHICS_HPP
#include "../headers/graphics.hpp"
#endif
#ifndef THREADS_HPP
#include "../headers/threads.hpp"
#endif

void Entity::load(std::vector<Entity*> *stack){
    id = stack->size();
    while(isStackInUse());
    setStackInUse(true);
    stack->push_back(this);
    if(surface!=NULL||sourcePath.empty()) return;
    surface = SDL_LoadBMP(sourcePath.c_str());
    texture = createDefaultTexture(surface);
    setStackInUse(false);
    if(surface==NULL){
        std::cout << "Failed to load " << sourcePath << "! (";
        std::cout << stack->at(id) << ")" << std::endl;
    }
}

void Entity::unload(std::vector<Entity*> *stack){
    while(isStackInUse());
    setStackInUse(true);
    stack->erase(stack->begin() + id);
    setStackInUse(false);

}

void Entity::free(){
    SDL_FreeSurface(surface); 
}