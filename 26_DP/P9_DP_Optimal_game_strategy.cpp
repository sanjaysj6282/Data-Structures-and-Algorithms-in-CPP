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

vi a;

// Recursion
int solve(int i, int j){
    if(i==j)
        return a[i];

    if(i>j)
        return 0;

    // Opponent chooses (i+1)th or jth coin to minimise your score
    // A[i..j], rem coins = A[i+1..j]
    int l = a[i] + min(solve(i+2, j), solve(i+1, j-1));
    // lly --> chooses (j-1)th or ith coin
    // A[i..j], rem coins = A[i..j-1]
    int r = a[j] + min(solve(i, j-2), solve(i+1, j-1));

    return max(l, r);
}

// Memoization
int dp[M][M];
int solve_m(int i, int j){
    if(i==j)
        return a[i];

    if(i>j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    // A[i..j], rem coins = A[i+1..j]
    int l = a[i] + min(solve_m(i+2, j), solve_m(i+1, j-1));
    // A[i..j], rem coins = A[i..j-1]
    int r = a[j] + min(solve_m(i, j-2), solve_m(i+1, j-1));

    dp[i][j] = max(l, r);


    return dp[i][j];
}

int main(){
    int n;
    cin >> n;
    a= vector<int>(n);
    for(auto &i : a)
        cin >> i;

    rep(i, 0, M)
        rep(j, 0, M)
            dp[i][j]=-1;

    cout << solve(0, n-1) << endl;

    cout << solve_m(0, n-1);

    return 0;
}