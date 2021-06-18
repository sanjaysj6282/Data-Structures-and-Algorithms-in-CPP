#include <iostream>
#include <vector>
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

// Visited vector;
bool vis[N];
// Adjacency list
vi adj[N];

// Stack based
void dfs(int node){
    
    vis[node]=1;

    // preorder
    // cout << node << " ";

    // Inorder
    vi :: iterator it;
    for(it=adj[node].begin(); it!=adj[node].end(); it++){
        if(!vis[*it])
            dfs(*it);
    }

    // postorder
    cout << node << " ";
}

int main(){
    for(int i=0; i<N; i++)
        vis[i]=0;

    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Since graph may be disconnected/connected
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    return 0;
}