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
   index in recursion stack/dfsVis

2. Fill all the vertices which are not visited and are 
   adjacent to current node

3. If the adjacent vertices are already marked in recursion 
   stack/dfsVis then a cycle is found
   
*/   

// DFS 
class Solution {
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
        vis[node] = 1; 
        dfsVis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) 
                if(checkCycle(it, adj, vis, dfsVis)) 
                    return true;
            // Means its vis[it]=1 and dfsVis[it]=1 return true
            else if(dfsVis[it]) 
                return true; 
        }

        dfsVis[node] = 0; 
        return false;
    }

public:
	bool isCyclic(int N, vector<int> adj[]) {
	   int vis[N], dfsVis[N]; 
	   memset(vis, 0, sizeof vis); 
	   memset(dfsVis, 0, sizeof dfsVis); 
	   
	    for(int i = 0;i<N;i++) 
	        if(!vis[i]) 
	            if(checkCycle(i, adj, vis, dfsVis))
	               return true; 
	    
	    return false; 
	}
};




int main(){
    int t;
    cin >> t;
    while(t--){
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++){
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
