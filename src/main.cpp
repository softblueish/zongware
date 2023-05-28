#ifndef GRAPHICS_HPP
#include "../headers/graphics.hpp"
#endif
#ifndef INPUT_HPP
#include "../headers/input.hpp"
#endif
#ifndef ENTITY_HPP
#include "../headers/entity.hpp"
#endif

const char* title = "Game";
std::vector<Entity*> stack;

int main(){
    startGraphics(title);
    
    // START TEST

    Entity zong("zong", 's', 0, 0, 640, 500, "../assets/sexy_ass_bitch.bmp");

    // END TEST

    while(true){
        if(shouldClose() || checkInput(SDLK_ESCAPE)) break;

        // START TEST

        if(checkInput(SDLK_w)){
            zong.y -= 10;
            std::cout << "w" << std::endl;
        }
        if(checkInput(SDLK_s)){
            zong.y += 10;
            std::cout << "s" << std::endl;
        }
        if(checkInput(SDLK_a)){
            zong.x -= 10;
            std::cout << "a" << std::endl;
        }
        if(checkInput(SDLK_d)){
            zong.x += 10;
            std::cout << "d" << std::endl;
        }
        if(checkInput(SDLK_l)){
            zong.load(&stack);
        }
        if(checkInput(SDLK_u) && stack.size() > 0){
            zong.unload(&stack);
        }
        std::cout << stack.size() << std::endl;

        // END TEST

        renderGraphics(&stack);
    }
    endGraphics();
}