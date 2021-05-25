#include <iostream>
using namespace std;

// Refer videos for "Techniques" --> VIMP

/*
Power of two
From our past knowledge of the binary number system,
Numbers of the type 2n have only 1 set bit.
Explanation:     n = 000100
             n - 1 = 000011
     n & ( n - 1 ) = 000000
!( n & ( n - 1 ) ) = 000001
If the number only had one set bit, then n & ( n - 1 ) would be zero.

Generate Subset
Explanation: if the jth bit is set, then we take the jth element.
There are a total of 2n subsets.

Count set bits
n & (n - 1) sets the first set-bit to zero.
Explanation:  n = XXX100
          n - 1 = XXX011
  n & ( n - 1 ) = XXX000

*/

bool ispowerof2(int n){
    // n && .. is used -->Since it's a Base/Corner case when n = 0
    // Since n-1 would be -ve
    // IMP ---> The whole expresssion would be 0
    return (n && !(n & n-1));
}

// Application of Powerof2
int numberofones(int n){
    int count = 0;
    while (n){
        n= n & n-1;
        count++;
    }
    return count;
}

// VIMP
void subsets(int arr[],int n){
    // 0 to 2^n - 1 or 1<<n
    for(int i=0;i< (1<<n);i++){
        for(int j=0;j<n;j++){
            // Get_bit function is used
            // To get at j'th position it's 1 or not for 0 to 2^n - 1
            if(i & (1<<j))
                cout << arr[j] << " ";
        }
        cout << "\n";
    }
}

int main(){

    cout <<ispowerof2(14) << "\n";

    cout <<numberofones(19) << "\n";

    int arr[4] = {1,2,3,4};
    subsets(arr,4);
    cout << "\n";
    
    return 0;
}