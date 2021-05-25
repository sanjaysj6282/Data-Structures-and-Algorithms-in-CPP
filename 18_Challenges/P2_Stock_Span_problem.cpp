#include "bits/stdc++.h"
using namespace std;


#define foi(n,m) for(int i=n;i<m;i++)
#define ve vector<int>

// int main(){
//     stack<pair<int,int>> span;
//     int n;
//     cin >> n;
//     int arr[n];
//     foi(0,n)
//         cin >> arr[i];

//     vector<pair<int,int>> v;

//     span.push(make_pair(arr[0],1));

//     foi(1,n){
//         int count = 1;
//         if(arr[i-1] > arr[i]){
//             span.push(make_pair(arr[i],1));
//         }
//         else{
//             while(!span.empty() and arr[i]>=arr[i-1]){
//                 span.pop();
//                 span.push(make_pair(arr[i],1+span.top().second));
//                 count++;
//             }
//             v.push_back({});
//         }
//         // cout << arr[i] << i << endl;
//     }

//     return 0;
// }

ve stockSpan(ve prices) {
    ve ans;
    stack<pair<int,int>> span;
    for(auto price:prices){
        int day = 1;
        while(!span.empty() and span.top().first <= price){
                day +=span.top().second;
                span.pop();
        }
        span.push({price,day});
        ans.push_back(day);
    }
    return ans;
}

int main(){
    ve prices ={100,80,60,70,60,75,85};
    ve ans = stockSpan(prices);
    for(auto days:ans){
        cout << days << " ";
    }
}

