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

/*

You are given n files, with their computation times in an Array. You can perform
the following operation
Operation:
Choose/ take any two files, add their computation times and append it to the list
of computation times. {Cost = Sum of computation times}
Do this until we are left with only one file in the array. We have to do this
operation so that we can get the minimum cost finally.

*/
/*
Approach
1. Push all elements to a min heap.
2. Take the top 2 elements one by one, and add the cost to the answer. Push
   the merged file to the min heap.
3. When a single element remains, output the cost.

*/

// Easy
signed main(){
    int n; cin >> n;
    vi a(n);
    
    priority_queue<int, vector<int>, greater<int>> q;

    rep(i,0,n){ 
        cin >> a[i];
        q.push(a[i]);
    }

    int ans=0;

    while(q.size() > 1){
        int top1 = q.top();
        q.pop();
        int top2 = q.top();
        q.pop();

        q.push(top1+top2);

        ans += top1+top2;
    }

    cout << ans << endl;

    return 0;
}