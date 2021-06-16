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

/*
    Algorithm
1. Keep on traversing the graph
2. If u find a node already visited(except parent node).
   a cycle is found
   
*/

// DFS 
bool isCycle(int src, vvi &adj, vector<bool> &vis, int parent){
    vis[src]=true;
    for(auto i: adj[src]){
        if(i != parent){
            if(vis[i])
                return true;

            if(!vis[i] && isCycle(i, adj, vis, src))
                return true;
        }
    }

    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vvi adj(n);

    rep(i, 0, m){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool cycle =false;
    vector<bool> vis(n, false);
    rep(i, 0, n)
        if(!vis[i] && isCycle(i, adj, vis, -1))
            cycle = true;
    
    if(cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl; 

    return 0;
}