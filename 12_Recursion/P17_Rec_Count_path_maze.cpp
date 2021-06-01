#include <iostream>
using namespace std;
/*
    CountPathMaze
    
Given a 2D grid, find the number of ways to reach (n-1, n-1).
You can go to (i,j) from (i-1,j) and (i,j-1).

Time Complexity: O(2n)
Space Complexity: O(2n)
*/
int countPathMaze(int n,int i,int j){
    if(i == n-1 && j == n -1 )
        return 1;

    if(i >= n || j >= n)
        return 0;

    // At each coordinate we can go both X and Y direction So we add
    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);
}

int main(){
    cout << countPathMaze(3,0,0) << endl;

    return 0;
}