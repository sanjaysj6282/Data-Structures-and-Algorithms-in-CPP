#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define vi vector<int> 
#define mi map<int, int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

// VIMP
// In both CP and Coding interviews
/*
   Optimized approach
1. Compute prefix sum array.
2. Main idea: For an array of prefix sum if a value repeats in prefix sum array
   at indices i and j, it denotes sum of elements from indices i+1 till j is zero.
   So, we have to find the number of ways in which we can choose two same valued
   elements in the PrefSum array. (Special case for PrefSum[i]=0, as they add upto
   zero from starting index)
3. Declare a map (say freq) denoting frequency of elements in the prefix sum
   array.
   map<int,int> freq;
4. Iterate over the PrefSum array and just do
   freq[PrefSum[i]]++;
5. After our freq map is created, then apply permutation and combination
   formula to choose 2 elements from the group of m identical items. (mC2)
   for each key

*/
int main(){
    int n;
    cin >> n;
    vi a(n);

    rep(i,0,n)
        cin >> a[i];

    mi cnt;
    int prefSum=0;

    rep(i, 0, n){
        prefSum +=a[i];
        cnt[prefSum]++;
    }

    int ans=0;
    mi :: iterator it;

    for(it=cnt.begin(); it != cnt.end(); it++){
        int m = it->second;
        // mC2 = (m*(m-1))/2
        ans += (m*(m-1))/2;
        if(it->first == 0)
            ans += it->second;
    }
    cout << ans << endl;

    return 0;
}