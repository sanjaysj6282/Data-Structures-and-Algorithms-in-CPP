#include <iostream>
#include <climits>
//  OR
// #include <limits.h>
using namespace std;

// Similar to Countpathmaze
// Refer to countpath algorithm
// Similar but Very different  

/* 
   Here we did'nt use "for loop"
   Since we know, when a tile is placed n--> n-1,n-2
   There it can move to s+1,2,3,4,5,6
*/
int tilingWays(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return tilingWays(n-1) + tilingWays(n-2);
}

// Tricky
int friendsPairing(int n){

    if(n == 0 || n == 1 || n == 2){
        return n;
    }

    // n- 1 == single  +  n-2 == paired * (n-1) == since there are n-1 ways to pair n person
    // i.e, if n = 4 there are 3 ways to pair a person
    // Consider 1st person there are 3 other persons to be paired with so hence 3 ways
    return friendsPairing(n-1) + friendsPairing(n-2) * (n-1);
}

// Famous Q
// VIMP
// Most IMP
// 0- 1 Knapsack Problem

// Think from recursive case and go to base case
int knapsack(int value[] , int wt[] , int n , int W){

    if(n == 0 || W == 0){
        return 0;
    }
    // Tricky
    // In "W-wt[n-1]" if wt[n-1] > W , 
    // Weight W becomes negative in next execution
    // So we can include only 2nd case 
    //i.e, Doesn't include nth item(weight can't be added) 
    if(wt[n-1] > W){
       return knapsack(value,wt,n-1,W);
    }

    // Read very carefully
    // Include n th item ,// Doesn't include nth item
    return max(knapsack(value , wt , n-1 , W-wt[n-1]) + value[n-1] , 
               knapsack(value , wt  , n-1 , W));
}

int main(){

    cout << tilingWays(4) << endl;

    cout << friendsPairing(4) << "\n";

    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;
    cout << knapsack(value,wt,3,W) << endl;



    return 0;
}