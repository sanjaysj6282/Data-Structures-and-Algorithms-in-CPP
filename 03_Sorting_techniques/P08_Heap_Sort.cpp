#include <iostream>
#include <vector>
using namespace std;

// One of best Sort to learn
//With this u will get a clear understanding of heaps

/*

What is Binary Heap? 
Complete BT is a BT in which every level, except possibly the last, is completely filled, 
and all nodes are as far left as possible 
(OR)  In array representation there should not be any space in b/w elements 
Complete BT where items are stored in a special order such that the value in a 
parent node is greater(or smaller) than the values in its two children nodes.
The heap can be represented by a binary tree or array.

If the parent node is stored at index I, the 
Left child can be calculated by 2 * I + 1 
Right child by 2 * I + 2 (assuming the indexing starts at 0).

Heap Sort Algorithm for sorting in increasing order: 
1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. 
   Replace it with the last item of the heap followed by reducing the size of heap by 1. 
   Finally, heapify the root of the tree. 
3. Repeat step 2 while the size of the heap is greater than 1.

How to build the heap? 
Heapify procedure can be applied to a node only if its children nodes are heapified. 
So the heapification must be performed in the bottom-up order.

*/

// Heapify down
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int> &a, int n, int i){
    // Initialize largest as root
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    // If left child is larger than root
    if(l<n && a[l]>a[largest])
        largest = l;

    // If right child is larger than largest so far
    if(r<n && a[r]>a[largest])
        largest = r;
    
    if(largest != i){
        swap(a[i], a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }

}

void heapsort(vector<int> &a){
    int n =a.size();
    
    // Step 1
    // Build heap (rearrange array) from last non leaf element
    for(int i=n/2-1; i>= 0; i--)
        heapify(a, n, i);
    
    // Step 2 and 3
    // One by one extract an element from heap
    for(int i=n-1; i>0; i--){
        // Move current root to end
        swap(a[0], a[i]);
        // call max heapify on the reduced heap heapify upto i
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