#include <iostream>
#include <string>
using namespace std;

// MostIMP
void keypad(string arr[], string s, string ans){
    if(s.length()==0){
        cout << ans << endl;
        return;
    }

    char ch=s[0];
    string newstring=arr[ch-'0'];
    string ros = s.substr(1);

    for(int i=0; i<newstring.length(); i++){
        keypad(arr, ros, ans+newstring[i]);
    }
}

int main(){
    string arr[]={"", "./", "abc", "def", "ghi", "jkl", "pqrs", "tuv", "wxyz"};
    keypad(arr, "23", "");

    return 0;
}