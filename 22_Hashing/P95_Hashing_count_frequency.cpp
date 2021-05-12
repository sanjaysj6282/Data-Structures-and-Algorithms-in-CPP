#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    map<int, int> freq; // or unordered_map

    // for(int i=0;i<n;i++)
    //     freq[a[i]]=0;

    for(int i=0;i<n;i++)
        freq[a[i]]++;
    
    map<int, int> :: iterator it;
    for(it=freq.begin(); it!=freq.end(); it++)
        // Similar to pair
        cout << it->first << " " << it->second << "\n"; 
}