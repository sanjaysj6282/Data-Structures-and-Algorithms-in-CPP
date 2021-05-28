#include <iostream>
using namespace std;

int divisible(int n, int a,int b){

    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);
    int T_stu = c1 + c2 - c3;
    return T_stu;
}

int gcd(int a,int b){

    while(b!= 0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int main(){

    int n;
    int a, b;
    cin >> n >> a >> b;

    cout << divisible(n,a,b) << endl;

    // GCD / HCF --- Euclid algorithm
    // 
     
    cout << gcd(a,b) << endl;

    return 0;
}