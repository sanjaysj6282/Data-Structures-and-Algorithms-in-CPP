#include <iostream>
#include <limits.h>
using namespace std;

/*
Idea: There will 2 cases,
To get the Min subarray we multiply the array by -1 and get the maximum sum
subarray.
Time Complexity: O(N)
*/
int kadane(int arr[],int n){
    int currentSum = 0;
    int max_Sum = INT_MIN;

    for (int i = 0; i < n; i++){
        currentSum += arr[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        max_Sum = max(max_Sum,currentSum);
    }
    return max_Sum;
}

void Maximum_Sum_Circular_Subarray(){

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int wrapsum;
    int nonwrapsum;
    int totalsum = 0;

    // Case 1
    nonwrapsum = kadane(arr,n);

    // Case 2
    // Max subarray sum = Total sum of array - Sum of non-contributing elements
    for (int i = 0; i < n; i++){
        // To find total sum ofr array
        totalsum += arr[i];
        // Convert each element to it's negative to find
        // non-contributing elements using "Kadane's Algorithm"
        arr[i] = -arr[i];
    } 
    // Subtracting the non countiguous element
    // kadane return {-ve value Sum of non-contributing elements}
    // wrapsum = totalsum - Sum of non-contributing elements
    wrapsum = totalsum + kadane(arr,n);

    // Best is selected
    cout << max(nonwrapsum,wrapsum) << "\n";
}

int main(){
    Maximum_Sum_Circular_Subarray();
    cout << endl;

    return 0;
} 