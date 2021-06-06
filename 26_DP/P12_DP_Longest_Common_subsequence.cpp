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
// In strings
/*

Problem
Given two strings S1 and S2. We need to output the length of 
longest common subsequence.

Example:
S1 = “RISHABH”
S2 = “SHUBHI”

Longest Common Subsequence = “SHBH”
Length of LCS = 4.

Brute force approach
1. Compute all subsequences of any of the string and check whether it is a
   subsequence of other string also.
2. Pick the one with maximum length.
                    Time Complexity: O(2^n)


Efficient Approach
Let f(i,j) denotes the length of LCS of S1[0, ...., i-1] and S2[0,...., j-1].
Two cases arise:
    A. S1[i-1] == S2[j-1]
        f(i,j) = 1 + f(i-1, j-1) {we take element in our LCS}
    B. S1[i-1] != S2[j-1], further two possibilities
        a. Take S1[i-1] in LCS.
        b. Take S2[j-1] in LCS.
                f(i,j) = max(f(i-1, j), f(i,j-1))

Note: Either if we do not take any of them, that case is also included 
      in the above possibilities.

Approach 1
1. Write the recursive solution.
2. Memoize it.

Approach 2
1. Build from base.
2. For every character of S1, iterate on every character of S2, 
   and apply the recurrence
        if(S1[i-1] == S2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1]
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
3. Output dp[n][m]

Where n - size of S1
      m - size of S2

                    Time Complexity: O(n*m)
*/

// Recursive
int lcs(string &s1, string &s2, int n, int m){
    if(n==0 || m==0)
        return 0;

    if(s1[n-1] == s2[m-1])
            return 1 + lcs(s1, s2, n-1, m-1);
    else
        return max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m));
}

// Memoization
int dp[M][M];

int lcs_m(string &s1, string &s2, int n, int m){
    if(n==0 || m==0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    if(s1[n-1] == s2[m-1])
        dp[n][m] = 1 + lcs_m(s1, s2, n-1, m-1);
    else
        dp[n][m] = max(lcs_m(s1, s2, n, m-1), lcs(s1, s2, n-1, m));

    return dp[n][m];
}

// Iteration/ Tabulation
int lcs_i(string &s1, string &s2, int n, int m){
    vvi dp(n+1, vi(m+1, -1));

    rep(i, 0, n+1){
        rep(j, 0, m+1){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n=s1.size();
    int m=s2.size();

    cout << lcs(s1, s2, n, m) << endl;

    rep(i, 0, M)
        rep(j, 0, M)
            dp[i][j] = -1;
    cout << lcs_m(s1, s2, n, m) << endl;

    cout << lcs_i(s1, s2, n, m) << endl;


    return 0;
}
