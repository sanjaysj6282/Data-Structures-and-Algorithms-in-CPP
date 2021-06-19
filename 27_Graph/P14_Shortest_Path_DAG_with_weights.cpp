#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
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

const int INF=1e9+7;

// Think in terms of DP (Very similar)
 
// Modified DFS/Topo sort (it can be done using BFS too)

// No need of visited array
// dist.Array to store length each length as infinity
// Queue stores the nodes and then mark its dist



void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) 
        if(!vis[it.first]) 
            findTopoSort(it.first, vis, st, adj); 
        
    st.push(node);
}


void shortestPath(int src, int N, vii adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 

	dist[src] = 0; 

	while(!st.empty()) {  
		int node = st.top(); 
		st.pop(); 
    
        // If the node has been reached previously
		if (dist[node] != INF) 
		    for(auto it : adj[node]) 
		        if(dist[node] + it.second < dist[it.first]) 
		            dist[it.first] = dist[node] + it.second; 
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 

int main() 
{ 
	int n, m;
	cin >> n >> m;
	vii adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 
