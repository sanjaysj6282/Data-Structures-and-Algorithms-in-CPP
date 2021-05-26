// VIMP
// MERGE SORT
// DIvide and conquer algorithm
// Similar to Binary search recursion 

#include <iostream>
using namespace std;
/*
    Merge sort
Idea: Divide the array into two parts, sort the left part and sort the right part and 
merge them

2 ptr approach used in Merge
 
Time Complexity: O(N logN) 
Space Complexity: O(N) Since we need an arbitrary array as well.
*/
void Merge(int arr[],int l,int mid,int r){

    int n1 = mid-l+1;
    int n2 = r-mid;
    // temp arrays
    int a[n1];
    int b[n2];  

    for(int i = 0; i < n1;i++)
        a[i]=arr[l+i];

    for(int i = 0; i < n2;i++)
        b[i]=arr[mid+1+i];

    // Pointers
    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    // VIMP
    // Corner case
    while(i < n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = b[j];
        k++;
        j++;
    }
}

void MergeSort(int arr[],int l,int r){

    if(l < r){
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);

        Merge(arr,l,mid,r);
    }
}
int main(){

    int arr[] = {5,4,3,2,1};

    MergeSort(arr,0,4);

    for(int i = 0;i < 5;i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

