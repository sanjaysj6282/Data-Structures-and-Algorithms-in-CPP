#include <iostream>
using namespace std;

void Sum(int N){
    int Sum = (N * (N+1))/2;
    cout << Sum;
    return;
}

int main(){
    int Number;
    cout << "Enter a number to find it's sum " << endl;
    cin >> Number;

    Sum(Number);

    cout << endl;

    return 0;
}