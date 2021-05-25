#include <iostream>
#include <limits.h>
using namespace std;

void Print_subarrays(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++){
        for (int j = i; j < n;j++){
            for (int k = i; k <= j;k++){
                cout << arr[k] << " ";
            }                                                                                   
            cout << endl;
        }
    }
}

void Max_Sum_Subarray(){

    //M1--Refer P13_Pr


    //M2 -- Average case complexity
    //O(N2)
    //Cumilative sum approach
    //Prefix sum technique
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cumsum[n+1];
    cumsum[0] = 0;

    for(int i = 1;i <=n;i++){
        cumsum[i] = cumsum[i - 1] + arr[i-1];
    }

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

// IMP
// Brute force approach
// We find all pairs using 2 for loops
// for i (0->n-1)
//   for j (i+1->n)
//      if(arr[i] + arr[j] == k)     
void Pair_Target_Sum_Problem(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Sorted array is given

    // Read & understand 
    int low = 0;
    int high = n-1;

    int k;
    cin >> k;

    // 2 pointer approach
    while (low < high){
        if(arr[low] + arr[high] == k){
            cout << low << " " << high << endl;
            cout << "True";
            return; 
        // OR break
        }
        else if (arr[low] + arr[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    cout << "False" 
}
int main(){

    Print_subarrays();
    cout << endl;

    Max_Sum_Subarray();    
    cout << endl;

    Maximum_Sum_Circular_Subarray();
    cout << endl;

    Pair_Target_Sum_Problem();
    cout << endl;

    return 0;
} 