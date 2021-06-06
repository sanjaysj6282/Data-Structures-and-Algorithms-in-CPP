#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int M=1e4+3, MOD=1e9+7;

// VIMP
// In placement and CP
// Refer P21_Knapsack in 12_Rec

int knapsack(int value[] , int wt[] , int n , int W){
    if(n <= 0 || W <= 0)
        return 0;

    if(wt[n-1] > W)
       return knapsack(value,wt,n-1,W);

    // Include n th item ,// Doesn't include nth item
    return max(knapsack(value , wt , n-1 , W-wt[n-1]) + value[n-1] , 
               knapsack(value , wt  , n-1 , W));
}

// Memoization
int dp[M][M];
int knapsack_m(int value[] , int wt[] , int n , int W){
    if(n <= 0 || W <= 0)
        return 0;

    if(dp[n][W] != -1)
        return dp[n][W];


    if(wt[n-1] > W)
        // Doesn't include nth item
       dp[n][W] = knapsack_m(value , wt  , n-1 , W);
    else{
        // Include n th item ,// Doesn't include nth item
        dp[n][W] = max(knapsack_m(value , wt , n-1 , W-wt[n-1]) + value[n-1], 
                       knapsack_m(value , wt  , n-1 , W));
    }

    return dp[n][W];
}

int main(){
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;
    cout << knapsack(value,wt,3,W) << endl;

    rep(i, 0, M)
        rep(j, 0, M)
            dp[i][j]=-1;
    

    cout << knapsack_m(value,wt,3,W) << endl;

    return 0;
}