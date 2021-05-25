#include <iostream>
#include <queue>
using namespace std;

// VIMP
// V HARD -->Try to remember as much as u can at least algorithm
/*
    Sliding window challenge
    In which each window of size k is taken and maximum of each k elements is found
    eg 1 2 3 4 5 6  k=3
       from 1 to 3 3 is maximum
       from 2 to 4 4 is maximum
       etc
*/

// Here we can use array to iterate and find it out -->THINK Y
// Here we use dequeue for most optimised solution-->O(N)


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i: a)
        cin >> i;

    // q is a "INDEX storing Dequeue"
    deque<int> q;
    vector<int> ans;

    // For 1st k elements
    /* 
        "Main Idea is to prevent it from Asc order" -->VVIMP so Desc order
        Since its Asc largest element of 1st k elements in front index,
        in dequeue and push the value to vector ans
    */
    // eg k=3, {5 4 3 2} --> q{0,1,2}

    for(int i=0;i<k;i++){
        while(!q.empty() and a[q.front()]<a[i])
            q.pop_back();
        
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    // For the next sets of elements
    /*
        Here we do same as in 1st step but 
        need to delete elements present in previos window if already present
        in stack so we use i-k (i-k is an element outside the current window)..... 
        eg. {1,2,3,4} for k=3 2nd window shouldnt contain 1 so
            if its index is present in q.front delete it
    */
    for(int i=k;i<n;i++){
        // Most IMP --> Look carefully
        // i-k to find the elements in each window which are
        // not a part of next window
        if(q.front()==i-k)  //i.e,
            q.pop_front();
        
        while(!q.empty() and a[q.front()]<a[i])
            q.pop_back();

        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for(auto i:ans)
        cout << i << " ";

    return 0;
}