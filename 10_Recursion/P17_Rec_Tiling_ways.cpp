#include <iostream>
#include <climits>
//  OR
// #include <limits.h>
using namespace std;
/*
    Tiling problem
//Find the number of ways to tile the floor with 1x2 and 1x1
Given 2*n board needs to be filled with 2*1 tiles
tiles. 
Idea: Tile[i] = Tile[i-1] (1x1) + Tile[i-2](1x2) 

Time Complexity: O(2n) 
Space Complexity: O(2n) //Memory is used for call stack as well 

*/
/* 
   Here we did'nt use "for loop"
   Since we know, when a tile is placed n--> n-1,n-2
   There it can move to s+1,2,3,4,5,6
*/
int tilingWays(int n){
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 1;
    
    return tilingWays(n-1) + tilingWays(n-2);
}

int main(){

    cout << tilingWays(4) << endl;

    return 0;
}