#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

// VIMP
// like BFS with priority queue
// Modified previous question
// Instead of queue, we use min heap;

int main(){
	int n,m,source;
	cin >> n >> m;
	vii g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pi, vii, greater<pi>> pq; // min-heap ; In pair => (dist,from)
	vi distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source)); // (dist,from)
	
	while(!pq.empty()){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vii::iterator it;
		for(auto it: g[prev]){
			int next = it.first;
			int nextDist = it.second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push({distTo[next], next});
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	
        cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}


