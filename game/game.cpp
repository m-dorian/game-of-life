 #include "../cell/cell.h"
 #include "game.h" 
 #include <vector>
#include <iostream>

bool Game::init() 
{ 
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
        return false; 
    }
    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN); 
    if(window == 0) 
    { 
        std::cout << "Error creating window: " << SDL_GetError() << std::endl; 
        return false; 
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == 0) 
    {  
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl; 
        return false; 
    }
    return true;
}
void Game::kill() 
{   
    SDL_DestroyWindow(window); 
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
void Game::createGrid()
{ 
        int x = 0;
        int y = 0;
        int i = 0;
        while( i < 72)
        {     
                if(rand() % 4 == 2) { 
                    state.push_back({x,y, true});
                } else state.push_back({x,y, false});
                x += 10; 
                if(x == 1280) 
                { 
                    y += 10; 
                    x = 0;
                    i++;
                }
        }
        for(size_t i = 0; i < state.size(); i++)
        { 
            state[i].top = findCell(state[i].x, state[i].y + 10); 
            state[i].bottom = findCell(state[i].x, state[i].y  - 10); 
            state[i].right = findCell(state[i].x + 10, state[i].y ); 
            state[i].left = findCell(state[i].x- 10, state[i].y ); 
            state[i].topRight = findCell(state[i].x + 10, state[i].y  + 10); 
            state[i].topLeft = findCell(state[i].x - 10, state[i].y  + 10); 
            state[i].bottomRight = findCell(state[i].x + 10, state[i].y  - 10); 
            state[i].bottomLeft = findCell(state[i].x - 10, state[i].y - 10); 
        }
    
}


bool Game::loop() 
{   
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
    SDL_RenderClear(renderer);
    SDL_Event event; 
    while(SDL_PollEvent(&event) != 0) 
    {   
        if(event.type == SDL_QUIT)
        { 
            return false;
        }
    } 
    
    for(int i = 0; i < state.size(); i++)
    { 
        state[i].checkNeighbors();
    }
    for(size_t i = 0; i < state.size(); i++) 
    { 
        if(state[i].alive) 
        {
        state[i].alive = state[i].neighbours == 2 || state[i].neighbours == 3;   
        }
        else 
        { 
        state[i].alive = state[i].neighbours == 3; 
        }
    }
   //Update window with current status of cells; 
     for(int i = 0; i < state.size(); i++) 
       {
        SDL_Rect rect = { state[i].x, state[i].y, 10, 10};
        if(state[i].alive) 
        { 
            SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);        
            SDL_RenderDrawRect(renderer, &rect);
            SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        else 
        { 
            SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);        
            SDL_RenderDrawRect(renderer, &rect);
            SDL_SetRenderDrawColor( renderer, 0, 0, 100, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
       }
    SDL_RenderPresent(renderer);
    return true; 
}
Cell* Game::findCell(int givenX, int givenY)
{ 
    for(int i = 0; i < state.size(); i++)
    { 
        if(state[i].x == givenX && state[i].y == givenY) return &state[i]; 
    }
    return nullptr; 
}

