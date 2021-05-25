#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

// VIMP Concept
// Used in many Greedy problems

/*
We are given n activities with their start and finish times. We have to select the
maximum number of activities such that no two selected activities overlap.

Approach

1. Sort all the activities by their finish times
2. Greedily select the first activity and jump on the next.
3. If the starting time of current activity is greater than  the ending time of
previously selected activity, then take it otherwise ignore it.

*/

/*
int main(){
    int n; cin >> n;
    vector<vi>  v;

    rep(i,0,n){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    // Custom comparator
    // [&]--> operator to denote function
    sort(v.begin(), v.end(), [&](vi &a, vi &b){
        return a[1] < b[1];
    });
    int take=1;
    int end = v[0][1];

    rep(i,1,n){
        if(v[i][0] >= end){
            take++;
            end=v[i][1];
        }
    }
    cout << take << endl;

    return 0;
}
*/

//      OR
// Easy to understand

bool compare(pair<int,int> t1, pair<int,int> t2) {
    if(t1.second == t2.second) 
        t1.first < t2.first;

    return t1.second < t2.second;
}

signed main() {
    int n; cin >> n;
    vector<pair<int,int>> times;

    for(int i=0; i<n; i++) {
        int st, fn;
        cin >> st >> fn;
        times.push_back({st,fn});
    }

    // Here we sort according to End time (i.e, times.second)
    sort(times.begin(), times.end(), compare);
    int ans = 1;
    int previousEndTime = times[0].second;

    for(int i=1; i<n; i++) {
        if(times[i].first >= previousEndTime) {
            ans++;
            previousEndTime = times[i].second;
        }
    }

    cout << ans << endl;
    
    return 0;
}
