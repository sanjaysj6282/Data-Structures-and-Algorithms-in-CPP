#include <iostream>
using namespace std;

// Never use it as we have STL-->stack 
// Here we use array to make a Stack
// Stack uses LIFO(Last In first out) OR FILA(First  In Last Out) policy
#define n 100000000
class stack{
    int *arr;
    int top;

    public:
    stack(){
        arr =new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1)
            cout << "Stack Overflow" << endl;
        
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top==-1)
            cout << "No element to pop " << endl;

        top--; 
    }

    // For both data member and function we cant use same string i.e, here "top"
    int Top(){
        if(top==-1){
            cout << "No element to pop " << endl;
        }
        return arr[top];
    }

    bool empty(){
        if(top==-1)
            return 1;

        return 0;
    }
};

int32_t main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;

    return 0;
}