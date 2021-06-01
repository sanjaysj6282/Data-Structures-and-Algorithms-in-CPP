#include <iostream>
using namespace std;

// Most IMP --> from these
// Look for execution pattern
// Both move all x and removedup are similar
string removeDup(string s){
    if(s.length() == 0)
        return "";
    
    // Study the execution very carefully
    char ch = s[0];
    // cout << s <<"  "<< ch << endl;

    // if(ch != NULL)
    // cout << ch << "\n";
    string ans = removeDup(s.substr(1));

    // To check the execution
    // cout << "ans= " << ans << " " <<"char= " << ch << "\n";

    if(ch == ans[0])
        return ans;
    
    return (ch + ans);
}

int main(){
    cout << removeDup("Saaam") << endl;
    
    return 0;
}