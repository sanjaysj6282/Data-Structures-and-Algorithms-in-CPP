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


// Greedy is a better approach

// Very llar to longest inc Subsequence
// Iterative
int jumpstoend(){
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n)
        cin >> arr[i];

    vi jumps(n, MOD);

    if(jumps[0]==0)
        return MOD;

    jumps[0]=0;
    rep(i, 1, n)
        rep(j, 0, i)
            // Check -- from "j" it can reach "i" 
            if((j + arr[j]) >= i)
                jumps[i]=min(jumps[i], 1+jumps[j]);
    
    return jumps[n-1];
}


int main(){
    
    cout << jumpstoend() << endl;

    return 0;
}