#include <iostream>
#include <limits.h>
using namespace std;

// IMP
// Brute force approach
// We find all pairs using 2 for loops
// for i (0->n-1)
//   for j (i+1->n)
//      if(arr[i] + arr[j] == k) 

/*
Pair Target Sum Problem
Find whether there exist 2 numbers that sum to K.
Important: The Array should be sorted for two pointer approach.
Idea: keep a low and high pointer, decide which pointer to move on the basis of
arr[low] + arr[high].
Time Complexity: O(N)
Space Complexity: O(1)
*/
void Pair_Target_Sum_Problem(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

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
        else if (arr[low] + arr[high] > k)
            high--;

        else
            low++;
    }
    cout << "False" 
}

int main(){
    Pair_Target_Sum_Problem();
    cout << endl;

    return 0;
} 