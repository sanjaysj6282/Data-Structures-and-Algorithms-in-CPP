#include <iostream>
using namespace std;

int sum(int n){
    if(n!=0)
        return n+ sum(n-1);
    
    else
        return 0; // stopping condition when n > 0
}

int main(){

    int n;
    cin >> n;
    cout << sum(n) << endl;
    cout << "\n";

    return 0;
}