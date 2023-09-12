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
    
    while(game.loop()) 
    { 
       SDL_Delay(100);
    }
    
    game.kill(); 
}