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

// Visited vector;
bool vis[N];
// Adjacency list
vi adj[N];

signed main(){
    for(int i=0; i<N; i++)
        vis[i]=0;

    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Since graph may be disconnected/connected
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            queue<int> q;
            // Let the 1st element be 1
            q.push(i);
            vis[i]=1;

            while(!q.empty()){
                int node=q.front();
                q.pop();

                // Printing BFS in order
                cout << node << endl;

                vi :: iterator it;
                // Better --> for(auto i:adj[node])
                for(it=adj[node].begin(); it!=adj[node].end(); it++){
                    if(!vis[*it]){
                        vis[*it]=1;
                        q.push(*it);
                    } 
                }
            }
        }
    }

    return 0;
}