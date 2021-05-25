#include <iostream>
using namespace std;

int sum(int n){

    if(n!=0){
        return n+ sum(n-1);
    }
    else{
        return 0; // stopping condition when n > 0
    }
}

int power(int n, int p){
    if(p!=0){
        return n * power(n,p-1);
    }
    else{
        return 1;
    }
}

int factorial(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

// Non Recursive 
// Some error
void fibonacciNR(int n){

    int a = 0;
    int b = 1;
    cout << a << b ;
    while(b <= n){

        int temp = a;
        a = b;
        b = temp + b;
        
        cout << a << b ;
    } 
}

// Recursive 
int fibonacci(int n){

    if(n == 0 || n == 1){  // base case
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){

    int n;
    cin >> n;
    cout << sum(n) << endl;
    cout << "\n";

    int p;
    cin >> p;
    cout << power(n,p) << endl;
    cout << "\n";

    cout << factorial(n) << endl;
    cout << "\n";

    cout << fibonacci(n) << endl;
    cout << "\n";

    return 0;
}