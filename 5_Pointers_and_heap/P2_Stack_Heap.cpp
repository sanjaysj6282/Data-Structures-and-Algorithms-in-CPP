#include <iostream>
using namespace std;

int main(){
    
    // Heap
    int a = 10;         // Stored in stack
    int *p = new int(); // Allocate memory in heap   ,p is a pointer to 10
    *p = 10;              
    delete(p);          // Deallocate memory  i.e value 10 gets removed but address remains 
                        // To solve the problem of "  Dangling pointer  "
    p = new int[4];     // To make a array of size 4 and p stores array's address i.e, 1st element of array
    delete[]p;          // delete the memory i.e, here array
    p = NULL;           // Destroys the pointer p containg address


    return 0;       
}