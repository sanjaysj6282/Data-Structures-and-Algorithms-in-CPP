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
#define rep(i,a,b) for(int i=a; i<b; i++)

#define ll long long

const int M=1e4+3, MOD=1e9+7;

// VIMP
// In strings

/*
Problem
You are given an array a[] of size n. Find the length of 
longest increasing subsequences.

Subsequence : "Part of the array in order". 
               It may or may not be continuous.


Approach (Tabulation)
1. Make a dp array and initialize all the dp[i] by 1 
   {since single element is also an LIS}.
2. For every i from left to right, iterate from j=0 to j=i-1 
   simultaneously checking
        if(a[i] > a[j])
            dp[i] = max(dp[i], 1+dp[j])
3. After loop ends, output dp[n-1]

   Time Complexity: O(n^2)

*/

// Memoization
int dp[M];
int Lis(vi &a, int n){
    if(dp[n]!= -1)
        return dp[n];

    // Single element is also a LIS
    dp[n]=1;

    rep(i, 0, n)
        if(a[n] > a[i])
            dp[n]= max(dp[n], 1+Lis(a, i));
    
    return dp[n];
}

// Iteration
int Lis_t(vi &a, int n){
    vi dp(n, 1);

    int ans=0;
    rep(i, 1, n){
        rep(j, 0, i)
            if(a[i]>a[j])
                dp[i]=max(dp[i], 1+dp[j]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
        cin >> a[i];
    
    
    rep(i, 0, n)
        dp[i]=-1;
    cout << Lis(a, n-1) << endl;

    cout << Lis_t(a, n) << endl;

    return 0;
}
