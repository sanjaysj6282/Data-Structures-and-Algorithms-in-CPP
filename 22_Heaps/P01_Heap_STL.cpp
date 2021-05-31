#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Heap is a special type of BT --> Not necessarily BST
// Mainly 2 types
// 1. Minheap
//    Subtree(Root->data) > data of all other sub nodes 
// 2. Maxheap
//    Subtree(Root->data) < data of all other sub nodes

#define vi vector<int>
#define rep(i, a, b) for(int i=a; i<b; i++);


int main(){
    
    // < Type, sequence/container [,Compaare]>
    // Sequence stores data 
    priority_queue<int,vi> pq;

    pq.push(2);
    pq.push(3);
    pq.push(1);
    
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << endl;

    priority_queue<int, vi, greater<int>> pqm;

    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    
    cout << pqm.top() << endl;
    pqm.pop();
    cout << pqm.top() << endl;

    
    return 0;
}