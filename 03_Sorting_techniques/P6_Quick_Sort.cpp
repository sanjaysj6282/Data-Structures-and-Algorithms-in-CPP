// Quick SORT
// DIvide and conquer algorithm
// Similar to Binary search recursion

// VIMP
// Hard

/*
    Quick sort
Idea: Select a random pivot, put it in its correct position, 
and sort the left and right part recursively.

Time Complexity: Avg = O(NlogN), Worst Case = O(N^2)

*/
#include <iostream>
using namespace std;

void swap(int arr[],int i,int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// MostIMP
// Look video for explanantion
int partition(int arr[],int l,int r){
    // Initialising pivot element as last one
    int pivot = arr[r];
    int i = l-1;
    for(int j = l;j < r;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
 
int QuickSort(int arr[],int l,int r){
    
    if(l < r){
        int pi = partition(arr,l,r);

        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,r);
    }
}
int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    QuickSort(arr,0,n-1);

    for(int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

