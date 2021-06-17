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
1. Traverse the graph
2. If the current node is of red color, paint
   its neighbours as blue

If u are able to color the graph successfully, then 
the graph is bipartite

*/


vi col;
vvi adj;
vector<bool> vis;
bool bipart=true;

// Current node "u" and current color "curr"
void color(int u, int curr){
    // If its coloured and its color is not as expected
    if(col[u]!=-1 && col[u]!=curr){
        bipart=false;
        return;
    }

    col[u]=curr;
    if(vis[u])
        return;

    vis[u]=true;
    for(auto i: adj[u]){
        // Interchanging 0 and 1
        color(i, curr xor 1);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    adj = vvi(n);
    vis = vector<bool>(n, false);
    col = vi(n, -1);

    rep(i, 0, m){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    rep(i, 0, n){
        if(!vis[i]){
            color(i, 0);
        }
    }

    if(bipart)
        cout << "Graph is bipartite" << endl;

    else
        cout << "Graph is not bipartite" << endl;

    return 0;
}