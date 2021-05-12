#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define vi vector<int> 
#define mi map<int, int> 
#define rep(i,a,b) for(int i=a;i<b;i++)
/*
   Optimal Approach (Sliding Window Technique)
   // Slide the window
1. Compute sum of first k elements by iterating from i=0 to i=k-1 and store it
   in the variable sum.
2. While increasing i, subtract a[i-1] and add a[i+k-1] in the previous sum,
   which will become the current sum. This step is known as moving window
   forward.
3. Keep a variable mn, which stores the minimum of the sum. 
   Operation used is
        mn = min(mn, sum)
                Time Complexity: O(n)

*/
int main(){
    int n, k;
    cin >> n >> k;

    vi a(n);

    rep(i, 0, n)
        cin >> a[i];
    
    int ans = INT32_MAX;
    int sum = 0;

    rep(i, 0, k)
        sum+=a[i];

    ans = min(ans, sum);

    rep(i, 1, n-k+1){
        sum -= a[i-1];
        sum += a[i+k-1];
        ans = min(ans, sum);
    }  

    cout << ans << endl;

    return 0;
}