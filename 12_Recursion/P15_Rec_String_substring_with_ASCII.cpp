#include <iostream>
#include <string>
using namespace std;

void subseq(string s, string ans=""){
    if(s.length()==0){
        cout << ans << endl;
        return;
    }

    char ch=s[0];
    string ros=s.substr(1);
    
    subseq(ros, ans);
    subseq(ros, ans+ch);
    subseq(ros, ans+to_string(ch));
}

int main(){
    string s="ABC";
    subseq(s);

    return 0;
}