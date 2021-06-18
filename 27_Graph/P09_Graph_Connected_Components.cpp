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
#define vpi vector<vii>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int N=1e4+3, MOD=1e9+7;

/*
    Algorithm
1. Visit the node in depth first fashion
2. If the node is not visited, visit that node
   and its neighbour recursively

Each time a unvisited node is found, a new component
will be found

*/

// Find the no of connected components in a graph
int get_comp(int idx, vector<bool> &vis, vvi &adj){
    if(vis[idx])
        return 0;

    vis[idx]=true;
    int ans=1;
    for(auto i: adj[idx]){
        if(!vis[i]){
            ans += get_comp(i, vis, adj);
            vis[i]=true;
        }
    }

    return ans;
}

/*
    Question
There are N friends numbered from 0 to N-1. You have to choose 2 person
such that they are not related to each other.
You are given information in the form of M pairs(X, Y) i.w, there is an
link between friend X and Y
Find out the no of ways in which 2 persons from diff groups can be chosen 

*/

int main(){
    int n, m;
    cin >> n >> m;

    vvi adj(n);
    vi components;
    vector<bool> vis(n, false);

    rep(i, 0, m){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    rep(i, 0, n)
        if(!vis[i])
            components.push_back(get_comp(i, vis, adj));
    
    for(auto i:components)
        cout << i << " ";
    cout << endl;

    // Question 2
    ll ans=0;
    for(auto i:components){
        // Adding all combination of selecting all(i) person in a 
        // connected graph and rest no of nodes = n-1 
        ans += i*(n-i);
    }

    // Since we take a person twice
    cout << ans/2 << endl;

    return 0;
}