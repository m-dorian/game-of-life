
#ifndef GAME
#define GAME
#include <SDL2/SDL.h>
#include <vector>
#include <../cell/cell.h>
class Game 
{ 
    public: 
        bool init(); 
        void kill(); 
        void createGrid();
        bool loop(); 
        Cell* findCell(int givenX, int givenY);
    private: 
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        std::vector<Cell>state;
        
}; 

#endif