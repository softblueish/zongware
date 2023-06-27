#ifndef ENTITY_HPP
#include <zongware/entity.hpp>
#endif
#ifndef GRAPHICS_HPP
#include <zongware/graphics.hpp>
#endif
#ifndef THREADS_HPP
#include <zongware/threads.hpp>
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
    if(texture==NULL){
        std::cout << "Failed to create texture from path " << sourcePath << "! (";
        std::cout << stack->at(id) << ")" << std::endl;
    }
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