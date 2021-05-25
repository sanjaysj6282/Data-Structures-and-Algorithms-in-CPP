#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void freq(){
    string s = "fedvragbkrewkjcbyaradacaz";

    int freq[26];
    for(int i = 0; i < 26;i++)
        freq[i] = 0;

    for(int i = 0; i < s.size();i++)
        // IMP
        freq[s[i] - 'a']++;

    char ans = 'a';
    int maxF = 0;

    for(int i = 0; i < 26;i++){
        if(freq[i] > maxF){
            maxF = freq[i];
            // IMP
            ans = i + 'a';
        }
    }

    cout << maxF << " " << ans << endl;

}
int main(){
    freq();

    return 0;
}
