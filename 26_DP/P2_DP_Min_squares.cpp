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
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int N=1e5+3, MOD=1e9+7;
/*
Problem
Given a number n, your task is to find the minimum number of numbers 
which sums to n.

Example
n = 26 = 4^2 + 3^2 + 1^2 {3 numbers}
or  26 = 5^2 + 1^2 {2 numbers}
So the minimum number of numbers required are 2

*/


// for 0 ={0^2}            i.e, no squares-->0;
//     1 ={1^2}                 1 sq
//     2 ={1^2 + 1^2}           2 sq.
//     3 ={1^2 + 1^2 + 1^2}     3 sq.


// Recursion --> llar to count paths (only in terms of control flow)
int minSquare(int n){
    if(n==0 || n==1 || n==2 || n==3)
        return n;

    int ans=MOD;
    for(int i=1; i*i<=n; i++)
        // Here we add 1 to represent that we included a no.
        ans=min(ans, 1 + minSquare(n-i*i));

    return ans; 
}


// Memoization (Top-Down)
int Dp[N];

int minSquare_m(int n){
    if(n==0 || n==1 || n==2 || n==3)
        return n;

    if(Dp[n]!=MOD)
        return Dp[n];

    for(int i=1; i*i<=n; i++)
        Dp[n]=min(Dp[n], 1 + minSquare(n-i*i));

    return Dp[n];
}

// Harder
// Tabulation (Bottom -up)
int minSquare_t(int n){
    vi dp(n+1, MOD);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=1; i*i<=n; i++)
        // It goes from i*i to last(n)
        for(int j=0; i*i + j<=n; j++)
            dp[i*i + j]=min(dp[i*i + j], 1+ dp[j]); // j <=n-i*i
    
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    rep(i, 0, N)
        Dp[i]=MOD;

    cout << minSquare_m(n) << endl;

    cout << minSquare_t(n) << endl;

    return 0;
}