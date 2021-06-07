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

const int N=1e4+3, MOD=1e9+7;


// Most IMP DP Problem
// Typical DP Problem

// Memoization is E when compared to iterative

/*

Problem
Given a set of coins and a value V. Find the number of ways in which we 
can make change of V.

Example
s={1, 2, 3}
V = 3
Possible ways to make change are {3}, {2,1}, {1,1,1}.
Note: {1,2} is not counted as a separate way as it is same as {2,1}.

To make ways with every coin, we have 2 options
A. Take it
B. Do not take it

*/



// Recursive
int coinChange(vi &a, int n, int x){
    if(x==0)
        return 1;
    
    if(x<0)
        return 0;

    if(n<=0)
        return 0;

    // Taken coin n + not taken
    return coinChange(a, n, x-a[n-1]) + coinChange(a, n-1, x);
}


// Memoization
int dp[N][N];

int coinChange_m(vi &a, int n, int x){
    if(x==0)
        return 1;
    
    if(x<0)
        return 0;

    if(n<=0)
        return 0;
    
    if(dp[n][x]!=-1)
        return dp[n][x];

    // Taken coin "n" + not taking "n"
    dp[n][x] = coinChange_m(a, n, x-a[n-1]) + coinChange_m(a, n-1, x);

    return dp[n][x];
}


// Tabulation / Iteration
int coinChange_i(vi &a, int n, int x){
    // Declare a 2D array of size (n+1)*(x+1)
    vvi dp(n+1, vi(x+1, 0));
    
    // For 0 valued coin to make 0 value
    dp[0][0] = 1;
    
    rep(i, 1, n+1){
        rep(j, 0, x+1){
            if(j-a[i-1] >= 0)
                // Taken coin "n" 
                dp[i][j] += dp[i][j-a[i-1]];

            // Not taking "n"
            dp[i][j] += dp[i-1][j];
        }
    }

    return dp[n][x];

    
    
    // Space 0(N)-->version

    // long long int table[n+1];         
    //      // Initialize all table values as 0         
    //      memset(table, 0, sizeof(table));         
    //      // Base case (If given value is 0)         
    //      table[0] = 1;         
    //      // Pick all coins one by one and update the table[] values         
    //      // after the index greater than or equal to the value of the         
    //      // picked coin         
    //      for(long long int i=0; i<m; i++)         
    //         for(long long int j=S[i]; j<=n; j++)         
    //             table[j] += table[j-S[i]]; 

}


int main(){
    int n;
    cin >> n;

    // Array of size n
    vi a(n);
    rep(i, 0, n)
        cin >> a[i];

    // Value 
    int x;
    cin >> x;
    cout << coinChange(a, n, x) << endl;

    rep(i, 0, N)
        rep(j, 0, N)
            dp[i][j]=-1;

    cout << coinChange_m(a, n, x) << endl;

    cout << coinChange_i(a, n, x) << endl;
        
    return 0;
}