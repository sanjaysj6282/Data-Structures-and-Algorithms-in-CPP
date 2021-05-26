#include <iostream>
#include <limits.h>
using namespace std;
/*

Maximum Sum Subarray Array
1. Brute Force:
Idea: For each subarray arr[i..j], calculate its sum.
Time Complexity: O(N3)

Space Complexity: O(1)2. Prefix Sum Technique:
Idea: For each subarray arr[i..j], calculate its sum. Using prefix sum can
reduce time to calculate the sum of arr[i..j] to O(1)
Time Complexity: O(N2)

Space Complexity: O(N)3. Kadane’s Algorithm:
Idea: Start taking the sum of the array, as soon as it gets negative, discard
the current subarray, and start a new sum.
Time Complexity: O(N)
Space Complexity: O(1)

*/

void Max_Sum_Subarray(){
    //M1--Refer P13_Pr


    //M2 -- Average case complexity
    //O(N2)
    //Cumilative sum approach
    //Prefix sum technique
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cumsum[n+1];
    cumsum[0] = 0;

    for(int i = 1;i <=n;i++)
        cumsum[i] = cumsum[i - 1] + arr[i-1];

    int maxSum = INT_MIN;

    for(int i = 1;i <=n;i++){
        int sum = 0;
        maxSum = max(maxSum,cumsum[i]);
        for (int j = 1;j <=i;j++){
            sum = cumsum[i] - cumsum[j-1];
            maxSum = max(maxSum,sum);
        }
    }
    cout << maxSum << endl;



    // VVIMP

    // M3 --Best case complexity
    // O(N)
    // Kadane's Algorithm
    
    int currentSum = 0;
    int max_Sum = INT_MIN;

    for (int i = 0; i < n; i++){
        currentSum += arr[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        max_Sum = max(max_Sum,currentSum);
    }
    cout << maxSum << endl;
}



int main(){
    Max_Sum_Subarray();    
    cout << endl;
    
    return 0;
} 