/*
Given an array arr[] of size N, check if it can be partitioned 
into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES

Explaination: 
The two parts are {1, 5, 5} and {11}

*/


#include <bits/stdc++.h>
using namespace std;

// Similar to 0-N Knapsack Problem
class Solution{
public:
    int dp[1001][1001];
    int subsetSum(int arr[], int N, int sum){
        
        if(N == -1){
            if(sum==0)
                return 1;
            return 0;
        }
        if(sum<0)
            return 0;
            
        if(sum==0)
            return 1;
            
        if(dp[N][sum] != -1)
            return dp[N][sum];
    
        return dp[N][sum] = subsetSum(arr, N-1, sum-arr[N]) || subsetSum(arr, N-1, sum);
        
        
        //return dp[N][sum];
    }
    int equalPartition(int N, int arr[]){
        int sum=0;
        for(int i=0; i<N; i++)
            sum += arr[i];
        
        if(sum & 1)
            return 0;
        
        int s=sum/2;
        dp[N][s];    
        memset(dp, -1, sizeof(dp));
        return subsetSum(arr, N-1, s);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}