// Bestsort ---> O(N)
// Count Sort
// Easy

/*
    Key Points
The O(N) sort.
Note  : Only limited to small positive integers only.
Input : Given an array.
Output: print the sorted array.

Time Complexity: O(N)
Space Complexity: O(max(Arr))

    Steps
Mainly
1. Find the count of every distinct element in the array
2. Calc the position of each element in the sorted array

*/
#include <iostream>
using namespace std;

void countSort(int arr[],int n){
    // To find max element in array
    int k = arr[0];
    for(int i = 0;i < n;i++)
        k = max(k,arr[i]);

    // To count no of each element
    int count[10] = {0};
    for(int i = 0;i < n;i++)
        count[arr[i]]++;

    // Prefix Sum finding for each index
    for(int i = 1;i <= k;i++)
        count[i]+=count[i-1];

    // IMP
    int output[n];
    // First need to decrement the count then store that 
    //particular index in the value of decremented count 
    for(int i = n-1;i >= 0;i--)
        output[--count[arr[i]]] = arr[i];
        // Equivalent to 
        // count[arr[i]]--;
        // output[count[arr[i]]=arr[i]

    // To make output array the initial array
    for(int i = 0;i < n;i++)
        arr[i] = output[i];
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    countSort(arr,9);

    for(int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}