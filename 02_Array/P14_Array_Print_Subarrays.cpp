#include <iostream>
#include <limits.h>
using namespace std;

void Print_subarrays(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++){
        for (int j = i; j < n;j++){
            for (int k = i; k <= j;k++){
                cout << arr[k] << " ";
            }                                                                                   
            cout << endl;
        }
    }
}


int main(){

    Print_subarrays();
    cout << endl;

    return 0;
} 