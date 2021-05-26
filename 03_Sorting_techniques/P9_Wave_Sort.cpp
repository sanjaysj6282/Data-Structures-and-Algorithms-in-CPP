// IMP
// Asked in Google and Amazon
// Wave Sort ---> Not a normal sort
// Easy

/*

Given an array, transform the array such that
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
        OR
arr[0]        arr[2]          arr[4]
      arr[1]          arr[3]          arr[5]

Input: Given an array.
Output: print the sorted array.

// O(N/2) --> O(N)  (N/2 can be written as N)
Time Complexity: O(N), single pass
Space Complexity: O(1)

*/
#include <iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[] , int n){
    // Starting from arr[1] then arr[3]...i.e, odd indices
    for(int i = 1; i < n;i+=2){
        if(arr[i] > arr[i-1])
            swap(arr,i,i-1);
        
        if(arr[i]>arr[i+1] && i <=n-2)
            swap(arr,i,i+1);      
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    waveSort(arr,n);

    for(int i = 0;i < n;i++)
        cout << arr[i] << " ";

    return 0;
}