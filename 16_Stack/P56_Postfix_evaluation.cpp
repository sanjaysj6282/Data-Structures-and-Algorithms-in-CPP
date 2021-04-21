#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

// for postfix look from last -->VIMP
// Understand the concept before jumping onto the problem

int postfix_eval(string s){
    stack<int> st;

    for(int i=0;i<s.length();i++){
        if('0' <= s[i] and s[i]  <= '9'){
            st.push(s[i]-'0');
        }
        else{
            // VIMP
            // op1 is the 1st element inserted
            int op2 =st.top();
            st.pop();
            int op1 =st.top();
            st.pop();

            switch(s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

int32_t main(){
    string s;
    s= "46+2/5*7+";
    cout<< postfix_eval(s) << endl;

    return 0;
}