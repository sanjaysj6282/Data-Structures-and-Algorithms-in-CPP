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

// Problem
// To find nth ugly no. (i.e, no with 2/3/5 factors only)
// eg. {1, 2, 3, 4, 5, 6, 8, 9, 10, 12}

// Similar to merging 3 sorted lists
int uglyno(int n){
    vi dp(n+1);

    int c2 = 0;
    int c3 = 0;
    int c5 = 0;

    dp[0]=1;
    for(int i=1; i<=n; i++){
        dp[i]=min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
        if(2*dp[c2]==dp[i])
            c2++;
        if(3*dp[c3]==dp[i])
            c3++;
        if(5*dp[c5]==dp[i])
            c5++;   
    }

    return dp[n-1];
}

int main(){
    int n;
    cin >> n;

    cout << uglyno(n) << endl;

    return 0;
}