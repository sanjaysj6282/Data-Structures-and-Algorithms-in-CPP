// Bestsort ---> O(N)
// Count Sort
// Hard --> think/??

#include <iostream>
using namespace std;

void countSort(int arr[],int n){

    int k = arr[0];
    // To find max element in array
    for(int i = 0;i < n;i++)
        k = max(k,arr[i]);

    int count[10] = {0};

    for(int i = 0;i < n;i++)
        count[arr[i]]++;

    for(int i = 1;i <= k;i++)
        count[i]+=count[i-1];

    // IMP
    int output[n];
    for(int i = n-1;i >= 0;i--)
        output[--count[arr[i]]] = arr[i];

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