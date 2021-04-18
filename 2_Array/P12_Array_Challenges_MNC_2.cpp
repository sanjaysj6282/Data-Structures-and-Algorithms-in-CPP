#include <bits/stdc++.h>
#include <iostream>
// #include <limits.h>
using namespace std;

// Oracle , Amazon
void First_Repeating_Element(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0;i < n;i++){
        cin >> arr[i];
    }

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


// AC method -- M1
// O(N) -- Best case



//    const int N = 1e6 + 2;
//  1e6... not working

    const int N = 100000;
    int idx[N];

    for (int i = 0;i < N;i++){
        idx[i] = -1;
    } 
    int minidx = INT_MAX;

    for (int i = 0;i < n;i++){
        if(idx[arr[i]] != -1){
            minidx = min(minidx,idx[arr[i]]);
        }
        else{
            idx[arr[i]] = i;
        }
    }

    if(minidx == INT_MAX){
        cout << "-1" << endl;
    }
    else{
        cout << minidx + 1 << endl;
    }

}

// Most IMP array Challenge Question
// Google, Amazon, Facebook, Visa
// 2 pointer approach
void Subarray_with_given_sum(){

    int n,s;
    cin >> n >> s;

    int a[n];

    for (int i = 0;i < n;i++){
        cin >> a[i];
    }

    int i = 0 , j = 0, st = -1, en = -1,sum =0;

    while(j < n && sum + a[j] <= s)
    {
        sum+= a[j];
        j++;
    }

    if (sum == s)
    {
        cout << i+1 << " " << j << endl;
        return;
    }

    while(j < n)
    {
        sum += a[j];
        while(sum > s)
        {
            sum -=a[i];
            i++;
        }
        if(sum == s)
        {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }

    cout << st << " " << en << endl;
}

// Easiest
// Amazon, Samsung, Snapdeal, Accolite
// Similar to First_Repeating_Element()
void Smallest_Positive_Missing_Number(){

    int n,s;
    cin >> n >> s;

    int a[n];

    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
//  const int N = 1e6 + 2;
//  1e6... not working
    const int N =10000;

    bool check[n];
    for (int i = 0;i < N;i++){
        cin >> check[i];
    }

    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            check[a[i]] = true;
        }
    }

    int ans = -1;

    for(int i = 1; i < N;i++){
        if(check[i] == false){
            ans = i;
            break;
        }
    }
    cout << ans << endl;

}

int main(){

    First_Repeating_Element();
    cout << endl;

    Subarray_with_given_sum();
    cout << endl;

    Smallest_Positive_Missing_Number();  
    cout << endl;


    return 0;
}