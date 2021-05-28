#include <iostream>
using namespace std;

/*
Arrays Challenge (Max till i)

Problem:
Given an array a[] of size n. For every i from 0 to n-1 output max(a[0], a[1],..., a[i]).
   Approach:
1. Keep a variable mx which stores the maximum till ith element.
2. Iterate over the array and update,
    mx = max(mx, a[i])

*/
//Max till i
int Max_till_i(int array[],int n){

    int Max = -199999;
    for (int i = 1;i < n;i++){
        if (Max < array[i])
            Max = array[i];
    }
    return Max;
}

int main(){

    int n;
    cout << "Enter the number of elements to be entered ";
    cin >> n;

    cout << endl;

    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    cout << endl;

    cout << "The Biggest element is" << Max_till_i(arr,n);
    cout << endl;

    return 0;
}