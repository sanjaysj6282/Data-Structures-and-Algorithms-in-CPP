#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define vii vector<pi>
#define rep(i,a,b) for(int i=a;i<b;i++)

bool compare(pi p1, pi p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1 > v2;
}

int main(){
    int n;
    cin >> n;

    vii a(n);

    rep(i,0,n)
        // {Value, weight}
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), compare);

    int w;
    cin >> w;
    
    int ans = 0;
    rep(i,0,n){
        if(w >= a[i].second){
            ans += a[i].first;
            w -= a[i].second;
            continue;
        }

        double vw = (double) a[i].first/a[i].second;
        ans += vw * w;
        w = 0;
        break;
    }
    
    cout << ans << endl;

    return 0;
}