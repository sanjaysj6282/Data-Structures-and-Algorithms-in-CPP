#include <iostream>
#include <climits>
//  OR
// #include <limits.h>
using namespace std;


// Famous Q
// VIMP
// Most IMP
// 0- 1 Knapsack Problem
/*
    Knapsack [IMP]

Given n items, each item has a certain value and weight. We have to maximize the
value of the objects we can accommodate in a bag of weight W.
Idea: For each item, we have two choices, either to include it or exclude it.

Time Complexity: O(2n)
Space Complexity: O(2n) //space for call stack

*/

// Think from recursive case and go to base case
int knapsack(int value[] , int wt[] , int n , int W){

    if(n == 0 || W == 0)
        return 0;
    
    // Tricky
    // In "W-wt[n-1]" if wt[n-1] > W , 
    // Weight W becomes negative in next execution
    // So we can include only 2nd case 
    //i.e, Doesn't include nth item(weight can't be added) 
    if(wt[n-1] > W)
       return knapsack(value,wt,n-1,W);
    
    // Read very carefully
    // Include n th item ,// Doesn't include nth item
    return max(knapsack(value , wt , n-1 , W-wt[n-1]) + value[n-1] , 
               knapsack(value , wt  , n-1 , W));
}

int main(){
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;
    cout << knapsack(value,wt,3,W) << endl;



    return 0;
}