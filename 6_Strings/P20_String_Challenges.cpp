#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void conversion(){

 // M1
    string str = "sxgfchvdccchj";
    // cout << 'a' - 'A' << endl;


    // converts into uppercase
    for(int i = 0; i < str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -=32;
        }
    }
    cout << str << endl;
    //converts to lower case
    for(int i = 0; i < str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] +=32;
        }
    }
    cout << str << "\n";

 // M2--Using functions
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << "\n";

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << "\n"; 
}

void biggest(){
    string s = "123467897";
    sort(s.begin(),s.end(),greater<int>{});

    cout << s[0] << "\n";

}
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

    conversion();
    
    biggest();

    freq();

    return 0;
}
