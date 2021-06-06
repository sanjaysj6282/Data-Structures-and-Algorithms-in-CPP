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

// Already did in Recursion

// Memoization
vi dp(M, MOD);
int friendsPairing(int n){
    if(n == 0 || n == 1 || n == 2)
        return n;
    
    if(dp[n]!=MOD)
        return dp[n];
    
    dp[n] = friendsPairing(n-1) + friendsPairing(n-2) * (n-1);

    return dp[n];
}

// Tabulation
int friendsPairing_t(int n){
    vi dp(n+1, 0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3; i<=n; i++)
        dp[i]=dp[i-1] + dp[i-2]*(i-1);

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << friendsPairing(n) << endl;

    cout << friendsPairing_t(n) << endl;

    return 0;

}