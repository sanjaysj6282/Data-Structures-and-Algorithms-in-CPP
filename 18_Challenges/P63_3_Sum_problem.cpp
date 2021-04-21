#include <iostream>
#include <algorithm> // For sorting function
#include <vector>
using namespace std;

// 2 pointer approach
// Time Complexity 
// Sort O(N*logN)
// 3_sum O(N*N) ,Since for*while loop
int32_t main(){
    int n;cin >>n;
    int target;cin >> target;
    // int arr[n];
    // for(int i=0;i<n;i++)
    //     cin >> arr[i];
    vector<int> arr(n);
    for(auto &i:arr){
        cin >> i;
    }
    
    bool found =false;

    // sort(arr,arr+n);
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        int l=i+1;
        int h=n-1;

        while(l<h){
            int current = arr[l]+arr[h]+arr[i];
            if(current == target){
                found = true;
            }
            if(current>target){
                h--;
            }
            else{
                l++;
            }
        }
    }
    if(found == true)
        cout << "True";
    else
        cout << "False";

    return 0;
}