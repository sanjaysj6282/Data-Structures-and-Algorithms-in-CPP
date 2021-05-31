#include <iostream>
using namespace std;

int power(int n, int p){
    if(p!=0)
        return n * power(n,p-1);

    else
        return 1;
}

int main(){
    int p;
    cin >> p;
    cout << power(n,p) << endl;
    cout << "\n";

    return 0;
}