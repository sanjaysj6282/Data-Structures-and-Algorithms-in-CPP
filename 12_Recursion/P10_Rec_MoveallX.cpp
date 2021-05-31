// Clue
// For almost all recursive string problems
// "substr(1)"is used
#include <iostream>
using namespace std;

// Hard
// See video
string moveallx(string s){
    if(s.length() == 0)
        return "";

    char ch= s[0];
    string ans = moveallx(s.substr(1));

    // The only difference between the both
    if(ch == 'x')
        return ans + ch;
    
    return ch +ans;
}

int main(){
    cout << moveallx("axxxxcxcbxerhsidznxzmxx") << endl;

    return 0;
}