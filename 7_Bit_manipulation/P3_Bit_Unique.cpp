// Refer notes and Videos

// Confusing 
// V Tricky Algorithm 
#include <iostream>
using namespace std;

/*
    Challenge 1
Write a program to find a unique number in an array where all numbers except
one, are present twice.
Hint: A ⊕ B ⊕ B ⊕ A ⊕ C = C. All those numbers which occur twice will get nullified
after ⊕ operation.

    Challenge 2
Q2. Write a program to find 2 unique numbers in an array where all numbers
except two, are present twice.
    Logic
1. Take XOR of all the elements and let that xor value be x. All the repeating
   elements will get nullified and xor of only two unique elements will last. (as a⊕a = 0).
2. There will be at least one bit set in x. Using that set bit, divide the original
   set of numbers into two sets
   a. First set which contains all the elements with that bit set.
   b. Second set which contains all the elements with that bit unset.
3. Take xor of both the sets individually, and let those xor values be x1 and x2.
4. Voila, x1 and x2 are our unique numbers. Reason: both the above sets
   contain one of the unique elements and rest elements of the sets occur
   twice which will get nullified after ⊕ operation.

    Challenge 3
Q3. Write a program to find a unique number in an array where all numbers
except one, are present thrice.
    Logic
1. We will maintain an array of 64 size which will store the number of times ith
   bit has occurred in the array.
2. Take the modulo of each element of this array with 3. Resultant array will
   represent the binary representation of the unique number.
3. Convert that binary number to decimal number and output it

*/

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