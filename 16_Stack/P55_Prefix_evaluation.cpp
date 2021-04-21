#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

// for prefix look from last --> VIMP
// Understand the concept before jumping onto the problem
// Use a testcase to find out op1 and op2

int prefix_eval(string s){
    stack<int> st;

    for(int i=s.length()-1;i>=0;i--){
        if('0' <= s[i] and s[i]  <= '9')
            st.push(s[i]-'0');
            
        else{
            // VIMP
            // op1 is the last element inserted -->like post element from last
            int op1 =st.top();
            st.pop();
            int op2 =st.top();
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
    s= "-+7*45+20";
    cout<< prefix_eval(s) << endl;

    return 0;
}