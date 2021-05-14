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

// Hard
// IMP in CP
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vii a(n);
        rep(i,0,n)
            cin >> a[i].ff >> a[i].ss;

        int l,p; cin >> l >> p;

        rep(i,0,n)
            a[i].ff = l-a[i].ff;
        
        sort(a.begin(), a.end());

        int ans=0;
        int currFuel=p;

        priority_queue<int,vi> pq;
        bool flag = 0;
        rep(i,0,n){
            if(currFuel >= l)
               break;
            
            while(currFuel < a[i].ff){
                if(pq.empty()){
                    flag=1;
                    break;
                }
                ans++;
                currFuel += pq.top();
                pq.pop();
            }
            if(flag)
                break;

            pq.push(a[i].ss);
        }

        if(flag){
            cout << -1 << endl;
            continue;
        }

        while(!pq.empty() and currFuel < l){
            currFuel += pq.top();
            pq.pop();
            ans++;
        }

        if(currFuel < l){
            cout << -1 << endl;
            continue;
        }

        cout << ans << endl; 
    }

    return 0;
}