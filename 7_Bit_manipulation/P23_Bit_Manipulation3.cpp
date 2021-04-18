// Refer notes and Videos

// Confusing 
// V Tricky Algorithm 
#include <iostream>
using namespace std;

// Single unique number
int unique1(int arr[],int n){
    int xorsum=0;
    for (int i = 0; i < n;i++){
        // ^ is XOR operator
        xorsum = xorsum^arr[i];
    //    cout << xorsum << endl;
    }
    return xorsum;
}

// To check wheather 1 is present or not
// Unlike Setbit --> in P21BitMan1
bool setBit(int n,int pos){
    return((n & (1<<pos))!=0);
}

// M-IMP
//
// 2 unique no
void unique2(int arr[],int n){
    int xorsum=0; // Gives xor of both unique no's
    for (int i = 0; i < n;i++){
        xorsum = xorsum^arr[i];
    }

    int tempxor = xorsum;

    // To get 1st(i,e, RightMost) "1" in the binary number
    int setbit=0;
    // To get the position of rightmost 1
    int pos=0;
    while(setbit!=1){
        // Last bit of xorsum is retrieved
        setbit = xorsum & 1;
        pos++;
        // To check the next position " >> " is done
        xorsum = xorsum >> 1;
    }

    int newxor=0; 
    for(int i=0;i<n;i++){
        // If its 1 then we xor
        if(setBit(arr[i],pos-1)){
            newxor=newxor^arr[i];
        }
    }  
    cout << newxor << "\n";
    cout << (tempxor^newxor) << "\n";
}

// To get i'th bit in each element 
bool getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}

// Put 1 At pos 
int Set_bit(int n,int pos){
    return(n | (1<<pos));
}

// 1 unique no others are Triplets  --> Different 
int unique3(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < 64; i++) {
        int sum = 0;
        // For getting each element in the array
        for (int j = 0; j < n; j++) {
            if (getBit(arr[j], i)) {
                sum++;
            }
        }
        if (sum % 3 != 0) {
            result = Set_bit(result, i);
        }
    }
    return result;
}

int main(){

    int arr[7] = {1,2,3,4,1,2,3};
    cout << unique1(arr,7) << endl;
    cout << "\n";

    int ar[8] = {1,2,3,1,2,3,5,7};
    unique2(ar,8);
    cout << "\n";
    
    int a[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
    cout << unique3(a, 10) << endl;

    return 0;
}