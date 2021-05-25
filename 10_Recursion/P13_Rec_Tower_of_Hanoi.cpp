#include <iostream>
using namespace std;

// Tricky
// VIMP
/*
    Tower of Hanoi

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
The objective of the puzzle is to move the entire stack to another rod, obeying the
following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on 
   top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.

Idea: move all the n-1 tiles to helper, and then place the remaining tile to dest and
then place those n-1 tiles back from helper to dest.

Time Complexity: O(2n)
Space Complexity: O(1)

*/
void Tower_of_Hanoi(int n,char src,char dest,char helper){
    if(n == 0)
        return; // Base case

    Tower_of_Hanoi(n-1,src,helper,dest);
    cout << "Move from " << src << " to" << dest << endl;
    Tower_of_Hanoi(n-1,helper,dest,src);

}


int main(){
    Tower_of_Hanoi(3,'A','C','B');
    cout << "\n";

    return 0;
}