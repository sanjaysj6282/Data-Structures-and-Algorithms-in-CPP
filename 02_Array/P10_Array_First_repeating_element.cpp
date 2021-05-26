#include <iostream>
#include <limits.h>
using namespace std;

// Oracle , Amazon
/*
Arrays Challenge-First Repeating Element
(Amazon, Oracle)
Problem
Given an array arr[] of size N. The task is to find the first repeating element in an
array of integers, i.e., an element that occurs more than once and whose index of
first occurrence is smallest.
Constraints
1 <= N <= 106
0 <= Ai <= 106
Example
Input:
7
1 5 3 4 3 5 6
Output:
2
Explanation:
5 is appearing twice and its first appearance is at index 2 which is less than 3
whose first occurring index is 3.
Solution
Base idea: To check if an element is repeating, we maintain an array idx[], which
stores the first occurrence (index) of a particular element a[i].
Steps
1. Initialise the idx[] with -1, and minidx with INT_MAX.
Array Challenges Part 22. Keep updating idx[], while traversing the given array.
*/

/*
    Constraints
    1 <= N <= 106
    0 <= Ai <= 106

So  time should be defaultly taken as 1 sec
So  O(N2 , NlogN)

*/

/*  Example of constraint analysis

    1 <= N <= 105
    1 <= N <= 108

    For Case 1
    We have to think of a better solution than O(N2), as in worst case, 
    it will perform 1010 operations as N is 105. So complexity acceptable
    for this case is either O(NlogN) which is approximately 106 (105 * ~10)
    operations well under 108 or O(N).

    For Case 2
    Even O(NlogN) gives us TLE as it performs ~109 operations which are 
    over 108. So the only solution which is acceptable is O(N) which in 
    worst case will perform 10^8 operations.

*/
void First_Repeating_Element(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0;i < n;i++)
        cin >> arr[i];

    // AC method -- M1
    // O(N) -- Best case

    //    const int N = 1e6 + 2;
    //  1e6... not working
    const int N = 100000;
    int idx[N];

    for (int i = 0;i < N;i++)
        idx[i] = -1;

    int minidx = INT_MAX;

    for (int i = 0;i < n;i++){
        if(idx[arr[i]] != -1)
            minidx = min(minidx,idx[arr[i]]);
        else
            idx[arr[i]] = i;
    }

    if(minidx == INT_MAX)
        cout << "-1" << endl;
    
    else
        cout << minidx + 1 << endl;

}

int main(){
    First_Repeating_Element();
    cout << endl;

    return 0;
}