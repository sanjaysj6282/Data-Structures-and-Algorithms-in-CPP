// Using STL
// Given an array nums of distinct integers, print all the possible permutations

#include "bits/stdc++.h"
using namespace std;



int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    
    cout << endl;

    vector<vector<int>> ans;

    sort(a.begin(),a.end());

    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(),a.end()));

    for(auto v : ans){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}