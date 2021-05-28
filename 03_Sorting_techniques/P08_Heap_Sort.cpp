#include <iostream>
#include <vector>
using namespace std;

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
    
    // Build heap (rearrange array)
    // from last non leaf element
    for(int i=n/2-1; i>= 0; i--)
        heapify(a, n, i);
    
    // One by one extract an element from heap
    for(int i=n-1; i>0; i--){
        // Move current root to end
        swap(a[0], a[i]);
        // call max heapify on the reduced heap
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