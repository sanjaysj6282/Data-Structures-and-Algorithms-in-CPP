#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define vi vector<int> 
#define mi map<int, int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

/*
   Approach
1. Create a map (say freq)
   map<int,int> freq;
2. While traversing the array keep track of elements and when we find 
   (k+1)th distinct element, break from the loop.
3. Output the element and frequency using map traversal
 
*/

int main(){
    int n, k;
    cin >> n >> k;

    vi a(n);

    rep(i,0,n)
        cin >> a[i];

    mi freq;

    rep(i, 0, n){
        // Here we check if Sizeof Map == k and if its distinct or not
        int presentSize = freq.size();
        if(freq[a[i]] == 0 and presentSize == k)
            break;
        
        freq[a[i]]++;
    }

    vector<pair<int, int>> ans;
    mi :: iterator it;
    for(it=freq.begin(); it != freq.end(); it++){
        // Corner case 
        // Since, for distinct element  --> we dont update freq[a[i]] 
        if(it->second != 0)
            // second is put 1st to print in Decreasing Order
            ans.push_back(make_pair(it->second, it->first));
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());

    vector<pair<int, int>> :: iterator it1;
    for(it1=ans.begin(); it1 != ans.end(); it1++)
        cout << it1->second << " " << it1->first << endl;

    return 0;
}