#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int N=1e5+3;


// Fibonacci No at a particular index
// Index : {1, 2, 3, 4, 5}
// Series: {0, 1, 1, 2, 3} or  may be {1, 1, 2, 3, 5}

// Recursive 
int fibonacci(int n){
    if(n == 0) 
        return 0;
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

// DP --> Memoization
// We add value to array for any new value obtained --> 
// So we can access it later on (Extra memory for remembering)
int dp[N];
int fib(int n){
    if(n==0 || n==1)
        return 0;
    if(n==2)
        return 1;
    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib(n-1)+fib(n-2);

    return dp[n];
}

// DP --> Tabulation
void fib_tabular(int n){
    vi DP(n+1);
    DP[0]=0;
    DP[1]=0;
    DP[2]=1;

    for(int i=3; i<=n; i++)
        DP[i]=DP[i-1] + DP[i-2];
    
    cout << DP[n] << endl;
}


int main(){
    int n;
    cin >> n;

    rep(i, 0, N)
        dp[i]=-1;

    cout << fibonacci(n) << endl;
    cout << fib(n) << endl;
    fib_tabular(n);
       


    return 0;
}
