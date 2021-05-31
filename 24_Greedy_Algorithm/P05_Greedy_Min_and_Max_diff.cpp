#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

int main(){
    int n;
    cin >> n;
    vi a(n);

    rep(i,0,n)
        cin >> a[i];

    sort(a.begin(), a.end());

    ll mn =0;
    ll mx =0;
    rep(i,0,n/2){
        mx +=(a[i+n/2]-a[i]);
        mn += (a[2*i+1]-a[2*i]);
    }
    cout << mn << " " << mx << endl;

    return 0;
}