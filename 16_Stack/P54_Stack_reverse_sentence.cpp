#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define ss stack<string>

// Easy
// Slightly tricky
void reverse(string s){

    ss st;

    /*
    // Here to print dont use << " " since space is already present
    // Just pop it and print elemts in LIFO
    string word="";
    s+=" "; // IMP Since a word is only considered when there is space after it
    for(int i=0;i<s.length();i++){
        word+=s[i];
        if(s[i] ==' '){
            st.push(word);
            word ="";
        }
    }
    */

    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' and i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int32_t main(){
    string s = "How are you reading";
    reverse(s);

    return 0;
}