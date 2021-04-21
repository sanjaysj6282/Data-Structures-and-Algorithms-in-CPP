#include <iostream>
#include <string>
#include <stack>
using namespace std;

// VIMP
// Steps
/*
    Steps
        1. Iterate the string rom 1st to last element 
        2. Compare
            a. if operand 
                  print
            b. if '('
                  push to stack
            c. if ')'
                  pop from stack and print until '(' is found
            d. if operator
                  pop from stack and print until an 
                  operator with less precedence is found
                  (i.e, if prec(top) > prec(s[i]) put it in res)
*/

int precedence(char c){
    if(c=='^')
        return 3;

    else if(c=='*' || c=='/')
        return 2;

    else if(c=='+' || c=='-')
        return 1;
    
    else 
        return -1;
}

string infixtopostfix(string s){
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() and st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() and precedence(st.top())>precedence(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

int32_t main(){
    cout << infixtopostfix("(a-b/c)*(a/k-l)") << endl;

    return 0;
}