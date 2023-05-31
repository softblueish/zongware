#ifndef THREADS_HPP
#include "../headers/threads.hpp"
#endif


bool stackInUse = false;
bool shouldGameExit = false;

void setStackInUse(bool inUse){
    stackInUse = inUse;
}

bool isStackInUse() {
    return stackInUse;
}

void exitGame(){
    shouldGameExit = true;
}

bool didGameExit(){
    return shouldGameExit;
}