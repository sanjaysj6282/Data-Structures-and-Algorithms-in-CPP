#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for(int i=a; i<b; i++)

// Very Easy
// IMP

/*
    Approach
1. Keep a MaxHeap and insert all the elements.
   MaxHeap
2. Keep popping the element and keep adding them to a variable sum and
   maintain their count
3. When sum becomes greater than or equal to k, break the loop and output
   the cnt.
        Time Complexity: O(nlog(n)
*/
int main(){
    int n, k;
    cin >> n >> k;

    int arr[n];
    priority_queue<int, vi> sortedArr;
    deque<int> ans;

    rep(i, 0, n){
        cin >> arr[i];
        sortedArr.push(arr[i]);
    }

    int sum = 0;
    int count = 0;
    while(!sortedArr.empty()){
        int Top = sortedArr.top();
        sum += Top;
        count++;
        sortedArr.pop();

        ans.push_back(Top);

        if(sum >= k)
            break;
    }

    if(sum < k)
        cout << -1 << endl;
    else
        cout << count << endl;

    return 0;
}