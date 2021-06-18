#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
1. Make the current node as visited and also mark
   index in recursion stack

2. Fill all the vertices which are not visited and are 
   adjacent to current node

3. If the adjacent vertices are already marked in recursion 
   stack then a cycle is found
   
*/   

// DFS 
bool isCycle(int src, vvi &adj, vector<bool> &vis, vi stack){  
    stack[src]=true;
    if(!vis[src]){
        vis[src]=true;
        for(auto i : adj[src]){
            if(!vis[i] && isCycle(i, adj, vis, stack))
                return true;

            if(stack[i])
                return true;
        }
    }
    stack[src]=false;
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
    }

    bool cycle =false;
    vi stack(n, 0);
    vector<bool> vis(n, false);
    rep(i, 0, n)
        if(!vis[i] && isCycle(i, adj, vis, stack))
            cycle = true;
    
    if(cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl; 

    return 0;
}