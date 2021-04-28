#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// IMP
// V Tricky but not hard
int32_t main(){

    string s;
    cin >> s;
    // Position storing vector with 256 indexes for ASCII value of each character 
    // whose dict[i] = -1, where 0<i<n i.e, all values -1
    vector<int> dict(256,-1);
    int maxLen=0;
    int start = -1;
    for(int i=0;i<s.size();i++){
        if(dict[s[i]] > start)
            start = dict[s[i]];
        
        dict[s[i]] = i;
        maxLen = max(maxLen,i-start);
    }
    cout << maxLen;

    return 0;
}