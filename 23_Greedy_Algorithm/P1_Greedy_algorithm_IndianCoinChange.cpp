#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

/*
    Problem
You are given an array of denominations and a value X. You need to find the
minimum number of coins to make value X.
{Note: We have an infinite supply of each coin.}
*/

/*
    Approach
1. Start from the largest value, till we can include it, take it.
2. Else move on the smaller value.

*/

int main(){
    int n;
    cin >> n;

    vi a(n);
    rep(i,0,n)
        cin >> a[i];

    int x;
    cin >> x;

    sort(a.begin(),a.end(), greater<int>());

    int ans = 0;
    // Note: A integer/ ineger is an integer in C++ by default
    // So x/a[i] is an int
    rep(i,0,n){
        ans += x/a[i];
        // x = x- remainder --> x is remaining amount
        x -= x/a[i] * a[i];
    }
    cout << ans << endl;

    return 0;
}