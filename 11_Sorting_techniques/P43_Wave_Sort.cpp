// IMP
// Asked in Google and Amazon
// Wave Sort ---> Not a normal sort
// Easy

// O(N/2) --> O(N)  (N/2 can be written as N)

#include <iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[] , int n){
    for(int i = 1; i < n;i+=2){
        if(arr[i] > arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]>arr[i+1] && i <=n-2){
            swap(arr,i,i+1);
        }
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