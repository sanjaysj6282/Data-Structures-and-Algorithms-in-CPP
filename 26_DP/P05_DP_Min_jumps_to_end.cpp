#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int N=1e4+3, MOD=1e9+7;


// Greedy is a better approach

// Very llar to longest inc Subsequence
// Iterative
int jumpstoend(){
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n)
        cin >> arr[i];

    vi jumps(n, MOD);

    if(arr[0]==0)
        return MOD;

    jumps[0]=0;
    rep(i, 1, n)
        rep(j, 0, i)
            // Check -- from "j" it can reach "i" 
            if((j + arr[j]) >= i)
                jumps[i]=min(jumps[i], 1+jumps[j]);
    
    return jumps[n-1];
}

// Optimised Min jumps Problem
class Solution{
  public:
    int minJumps(int arr[], int n) 
    { 
          
        // The number of jumps needed to reach the starting index is 0 
        if (n <= 1) 
            return 0; 
      
        // Return -1 if not possible to jump 
        if (arr[0] == 0) 
            return -1; 
      
        // initialization 
        int maxReach = arr[0]; // stores all time the maximal reachable index in the array. 
        int step = arr[0];     // stores the number of steps we can still take 
        int jump =1;//stores the number of jumps necessary to reach that maximal reachable position. 
      
        // Start traversing array 
        int i=1; 
        for (i = 1; i < n; i++) 
        { 
            // Check if we have reached the end of the array 
            if (i == n-1) 
                return jump; 
      
            // updating maxReach 
            maxReach = max(maxReach, i+arr[i]); 
      
            // we use a step to get to the current index 
            step--; 
      
            // If no further steps left 
            if (step == 0) { 
                // we must have used a jump 
                jump++; 
      
                // Check if the current index/position or lesser index 
                // is the maximum reach point from the previous indexes 
                if(i >= maxReach) 
                    return -1; 
      
                // re-initialize the steps to the amount 
                // of steps to reach maxReach from position i. 
                step = maxReach - i; 
            } 
        } 
        return -1; 
    }
};

int main(){
    
    cout << jumpstoend() << endl;

    return 0;
}