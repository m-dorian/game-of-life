#ifndef CELL 
#define CELL 
#include <vector>
struct Cell 
{   
    bool alive; 
    int x; 
    int y;  
    int neighbours;
    Cell(int a, int b, bool c) {x = a; y = b; alive = c;};
    Cell() {x = 0; y = 0; alive = false;};
    void checkNeighbors();
    Cell* top; 
    Cell* bottom; 
    Cell* right; 
    Cell* left; 
    Cell* topRight; 
    Cell* topLeft; 
    Cell* bottomRight; 
    Cell* bottomLeft; 
};  
#endif 