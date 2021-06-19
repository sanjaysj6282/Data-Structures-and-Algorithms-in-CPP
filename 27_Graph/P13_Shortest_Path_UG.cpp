#include <iostream>
#include <vector>
#include <queue>
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

const int N=1e4+3, MOD=1e9+7;

// Think in terms of DP (Very similar)
 
// Modified BFS
// Assume weight of each edge to be unity
// dist.Array to store length each length as infinity
// Queue stores the nodes and then mark its dist


/*
    Wrong 

    arr[i]=0; --> when push into the Q initially
    arr[adj[*it]]=min(arr[adj[*it]], arr[node]+1) --> 1st in loop

    Since even if we update dist from reduced node(it)
    then its not inserted in Q then it will not the subsequent
    nodes of it 
*/

// Better
// Here visited array is not needed 
void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) 
        dist[i] = INT_MAX; 

	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(!q.empty()) { 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
            // dist[it]=min(dis[it], dist[node]+1)
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 

	for(int i = 0;i<N;i++) 
        cout << dist[i] << " "; 
} 


// Adjacency list
vi adj[N];

int main(){
    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Let the initial element be 0
    BFS(adj, n, 0);

    return 0;
}