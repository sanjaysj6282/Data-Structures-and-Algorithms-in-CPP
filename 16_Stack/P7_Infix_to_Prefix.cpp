#include <iostream>
#include <string>
#include <algorithm> // Since it includes sort algorithm
#include <stack>
using namespace std;

// VIMP
// Steps
/*
    Steps
        1. Reverse the string
        2. Interchange ( --> ) 
        // Here we use the same logic as to postfix
        3. Iterate the string rom 1st to last element 
        4. Compare
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
        // VIMP
        4. reverse the string
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

string infixtoprefix(string s){

    reverse(s.begin(),s.end());
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
            res+=s[i];
        }
        // We changes "("<-->")"  
        // here we did Step 2 easily rather than changing it before
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() and st.top()!=')'){
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
    reverse(res.begin(),res.end());
    return res;
}

int32_t main(){
    cout << infixtoprefix("(a-b/c)*(a/k-l)") << endl;

    return 0;
}