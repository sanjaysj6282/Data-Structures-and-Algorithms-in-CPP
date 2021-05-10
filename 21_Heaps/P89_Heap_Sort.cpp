#include <iostream>
#include <vector>
using namespace std;

// Heap is a special type of BT --> Not necessarily BST
// Mainly 2 types
// 1. Minheap
//    Subtree(Root->data) > data of all other sub nodes 
// 2. Maxheap
//    Subtree(Root->data) < data of all other sub nodes


void heapify(vector<int> &a, int n, int i){
    int maxIdx = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n and a[l]>a[maxIdx])
        maxIdx = l;

    if(r<n and a[r]>a[maxIdx])
        maxIdx = r;

    if(maxIdx != i){
        swap(a[i], a[maxIdx]);
        heapify(a, n, maxIdx);
    }

}

void heapsort(vector<int> &a){
    int n =a.size();
    
    // from last non leaf element
    for(int i=n/2-1; i>= 0; i--)
        heapify(a, n, i);
    
    for(int i=n-1; i>0; i--){
        swap(a[0], a[i]);
        // heapify upto i
        heapify(a, i, 0);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin >> a[i];

    heapsort(a);

    for(int i=0;i<n;i++)
        cout << a[i] << " ";

    return 0;
}