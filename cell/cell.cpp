#include "cell.h"
void Cell::checkNeighbors() 
{  
    neighbours = 0;
   if(top && top->alive) neighbours++; 
   if(bottom && bottom->alive) neighbours++; 
   if(right && right->alive) neighbours++; 
   if(left && left->alive) neighbours++; 
   if(topRight && topRight->alive) neighbours++; 
   if(topLeft && topLeft->alive) neighbours++; 
   if(bottomRight && bottomRight->alive) neighbours++; 
   if(bottomLeft && bottomLeft->alive) neighbours++; 
}

