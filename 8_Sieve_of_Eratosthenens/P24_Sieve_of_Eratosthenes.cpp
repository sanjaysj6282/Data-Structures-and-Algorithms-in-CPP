#include <iostream>
using namespace std;


// Used to get prime numbers
void PrimeSieve(){

    int n;
    cin >> n;
    int prime[100]  = {0}; // use to declare array _ all elements 0 

    for(int i = 2; i <= n;i++){
        if(prime[i] == 0){
            for(int j = i * i;j <= n;j+=i){
                prime[j] = 1;
            }
        }
    }

    for(int i = 2; i <= n;i++){
        if(prime[i] == 0){
            cout << i << " ";
        }
    }cout << endl;

}

int main(){

    PrimeSieve();

    return 0;
}