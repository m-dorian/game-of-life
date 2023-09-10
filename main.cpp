#include "game/game.h"
#include <algorithm>
#include <time.h>
#include <fstream> 
#include <iostream>
int main()
{   
    srand(time(0));
    Game game; 
    if(!game.init()) return 1; 
    game.createGrid();
    std::ofstream of{"debug.txt"}; 
    //for(auto c : game.state)
    { 
        //of << c.bottom->x << " " << c.bottom->y << '\n'; 
    }
    //std::cout << game.state.size();
    while(game.loop()) 
    { 
       SDL_Delay(100);
    }
    
    game.kill(); 
}