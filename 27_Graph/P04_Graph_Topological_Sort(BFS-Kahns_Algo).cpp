#include <iostream>
#include <vector>
#include <queue>
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

// Topo sort is only present in "DAG"
int main(){
    int n, m; 
    cin >> n >> m;

    vi adj[N];
    vi indeg(n, 0);

    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;

        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> pq;
    rep(i, 0, n)
        if(indeg[i]==0)
            pq.push(i);

    // int cnt=0;
    while(!pq.empty()){
        // cnt++;
        int x=pq.front();
        pq.pop();
        cout << x << " ";

        for(auto it: adj[x]){
            indeg[it]--;
            if(indeg[it]==0)
                pq.push(it);
        }
    }


    return 0;
}