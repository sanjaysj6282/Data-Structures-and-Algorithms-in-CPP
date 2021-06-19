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
    Many ideas
1. To make queue<pair> to store element with color
2. Normal method

*/

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } 
            else if(color[it] == color[node]) 
                return false; 
        }
    }
    
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) 
        if(color[i] == -1) 
            if(!bipartiteBfs(i, adj, color))
                return false;

    return true; 
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) 
	    cout << "yes"; 
    else 
	    cout << "No"; 
	
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/



