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

// Here the difference is one item can be taken infinite times
// Only 2 difference b/w 0-1 and 0-N knapsack

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
        dp[n][W] = max(knapsack_m(value , wt , n, W-wt[n-1]) + value[n-1], 
                       knapsack_m(value , wt  , n-1, W));
    }

    return dp[n][W];
}

int knapsack_t(int value[] , int wt[] , int n , int W){
    vi dp(W+1, 0);

    // For each weight run through all n weights and check
    // If taking the element its better or not
    for(int j=0; j<=W; j++)
        for(int i=0; i<n; i++)
            if(j-wt[i] >= 0)
                dp[j]=max(dp[j], value[i]+dp[j-wt[i]]);
        
    return dp[W];
}

int main(){
    int wt[] = {3, 2, 4, 5, 1};
    int value[] = {4, 3, 5, 6, 1};
    int W = 11;

    rep(i, 0, M)
        rep(j, 0, M)
            dp[i][j]=-1;
    

    cout << knapsack_m(value,wt,5,W) << endl;

    cout << knapsack_t(value, wt, 5, W) << endl;

    return 0;
}