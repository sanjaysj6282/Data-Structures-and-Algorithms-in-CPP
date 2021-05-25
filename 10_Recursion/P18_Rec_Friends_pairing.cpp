#include <iostream>
#include <climits>
//  OR
// #include <limits.h>
using namespace std;

/*
    Friends Pairing Problem
    
There are n friends, we have to find all the pairings possible. Each person can be
paired with only one person or does not pair with anyone.
Idea: we have two options, i’th friend does not get paired or we have n-1 options
      to pair it with anyone.

Time Complexity: O(n)
Space Complexity: O(n)

*/

// Tricky
int friendsPairing(int n){

    if(n == 0 || n == 1 || n == 2){
        return n;
    }

    // n- 1 == single  +  n-2 == paired * (n-1) == since there are n-1 ways to pair n person
    // i.e, if n = 4 there are 3 ways to pair a person
    // Consider 1st person there are 3 other persons to be paired with so hence 3 ways
    return friendsPairing(n-1) + friendsPairing(n-2) * (n-1);
}


int main(){

    cout << friendsPairing(4) << "\n";

    return 0;
}