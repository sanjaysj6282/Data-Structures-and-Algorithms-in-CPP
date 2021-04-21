#include <iostream>
#include <stack>
using namespace std;
// Macros
#define si stack<int> 

// Space Complexity -->O(n)
void reverseStack(si &st){
    si newst;
    while(!st.empty()){
        newst.push(st.top());
        st.pop();
    }
    st = newst;
}

// To reduce space comp --> O(1)
// Recursive
// Hard

/*
  Better to remember rathan than thinking
  Which may be really time consuming if done otherwise
*/

/*
  to place a element at bottom we have to take every
  element from stack and pop it
  place it in a call stack
  when old stack is empty push the bottom element
  and then reverse it i.e, by pushing callstacks top element 
*/
void insertAtBottom(si &st,int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);

    st.push(topele);
}

/*
  Imagine as it gives a reversed stack with elements to be added at bottom
  insertAtBottom takes care of it
*/
void reverseRec(si &st){
    if(st.empty())
        return;

    int ele=st.top();
    st.pop();
    reverseRec(st);
    insertAtBottom(st,ele);
}

int32_t main(){

    si st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // reverseStack(st);
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }cout << endl;

    reverseRec(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }cout << endl;

    return 0;
}