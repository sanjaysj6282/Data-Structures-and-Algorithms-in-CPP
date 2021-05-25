#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define pii pair<int,int>

/*
Problem
Given k sorted arrays, our task is to combine all of them in such a way that the
final array is also a sorted array.
*/

/*
   Efficient Solution (Using heaps)

1. Create a MinHeap of pairs, i.e.
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >

2. Insert {first element, array number} of all the sorted arrays into MinHeap.

3. Pop the top element from the MinHeap and store it into the answer array.
   Insert the next element of the sorted array into the MinHeap.

4. Keep track of indices of the elements that are being inserted in the answer
   array using an index array[] whose indices denote the array number and
   elements represent the index of the last element inserted from that
   particular array

// Hint
   To Sort in decreasing order  --> max heap instead of min heap

*/


// Hard
// Read very carefully
int main(){
    // No of arrays
    int k;
    cin >> k;

    // 2D vector of K sorted arrays
    vector<vector<int>> a(k);

    rep(i,0,k){
        int size;
        cin >> size;

        // declaring a[i] as a vector of size "size"
        a[i] = vector<int>(size);

        /*
            i,j  j+1  j+2 ....size
            i+1
            .
            .
            k
        */
        rep(j, 0, size)
            cin >> a[i][j];

    } 

    // To "Store index of each sorted array"
    // In default it contains  index of each array as 0
    vi idx(k, 0);

    // [{value1, array no1}, {value2, array no2},....]
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Pushing 1st elements of each sorted array
    rep(i, 0, k)
        pq.push({a[i][0], i});

    vi ans; // Merged sorted array

    // Similar to level order traversal in BT
    while(!pq.empty()){
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        // MIMP
        // x.second --> array no
        // idx[arr no] --> i.e, current index of curr array
        // It checks index of curr array <= current array size
        if(idx[x.second]+1 < a[x.second].size())
            // pq.push({value, arr no})
            // value = a[array no][index(refer above)]
            pq.push({a[x.second][idx[x.second]+1], x.second});

        // Increasing Id of arr1,2,3 by 1
        idx[x.second] += 1;        
    }

    rep(i, 0, ans.size())
        cout << ans[i] << endl;

    cout << endl;

    return 0;
}