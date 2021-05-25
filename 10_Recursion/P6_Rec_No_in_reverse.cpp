#include <iostream>
using namespace std;

void dec(int n){
    if (n == 0)
        return;

    cout << n << endl;
    dec(n-1);  
}

// VIMP --> Reversion concept
// understand the difference between inc & dec
void inc(int n){

    if (n == 0)
        return;
    
    inc(n-1);
    cout << n << endl;
}


int main(){
    int n;
    cin >> n;
    dec(n);
    cout << endl;
    
    inc(n);
    cout << endl;

    return 0;
}