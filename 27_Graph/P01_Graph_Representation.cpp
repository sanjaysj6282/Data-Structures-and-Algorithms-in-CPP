#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int M=1e4+3, MOD=1e9+7;


// Adjacency list
vi adj[M];

signed main(){
    // No of elements, edges
    int n, m;
    cin >>n >> m;

    // Adjacency matrix
    vvi adjm(n+1, vi(n+1, 0));

    rep(i, 0, m){
        int x,y;
        cin >> x >> y;

        adjm[x][y]=1;
        adjm[y][x]=1;
    }

    cout << "Ajacency matrix :" << endl;
    rep(i, 1, n){
        rep(j, 1, n+1)
            cout << adjm[i][j] << " ";  
        cout << '\n';
    }

    if(adjm[3][7]=1)
        cout << "There is a edge" << '\n';
    else
        cout << "No there isnt a edge" << '\n';



    // Adjacency list
    rep(i, 0, n){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "adjacency list of graph" << endl;
    rep(i, 1, n+1){
        cout << i << "->";
        for(int x: adj[i])
            cout << x << " ";

        cout << endl;
    }


    return 0;
}