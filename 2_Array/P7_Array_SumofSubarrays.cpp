#include <iostream>
using namespace std;

/*
Arrays Challenge-Sum of all Subarrays
Question
Given an array a[] of size n. Output sum of each subarray of the given array.
Idea: Iterate over all subarrays and output the sum after each iteration.
    Approach
1. Write a nested loop, where outer loop runs from i=0 to i=n-1 and inner loop
   runs from j=i to j=n-1.
2. Keep a curr variable which stores the sum from i to j.
3. Output curr after each iteration of inner loop. After inner loop ends, update
   curr = 0

*/
//Sum of each Subarray
void Sum_Subarrays(int array[],int n){

    int curr = 0;
    for(int i = 0;i < n;i++){
        curr = 0;
        for (int j = i; j < n;j++){
            curr += array[j];
            cout << curr << endl;
        }        
    }
}

int main(){

    int n;
    cout << "Enter the number of elements to be entered ";
    cin >> n;

    cout << endl;

    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    cout << "Sum of subarrays" << endl;
    Sum_Subarrays(arr,n);
    cout << endl;

    return 0;
}