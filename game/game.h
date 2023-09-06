#pragma once 
#ifndef GAME
#define GAME
#include <SDL2/SDL.h>
class Game 
{ 
    public: 
        bool init(); 
    private: 
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
}; 
#endif