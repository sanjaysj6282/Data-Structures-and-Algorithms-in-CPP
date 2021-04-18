#include <iostream>
using namespace std;

void pointer_array(){

    //           x  x+4 x+8
    int arr[] = {10,20,30};
    cout << *arr << endl;
    cout << endl;

    int *ptr = arr;

    for(int i = 0; i < 3;i++){
        cout << *ptr << endl;
        ptr++;
    }
    cout << endl;

    for(int i = 0; i < 3;i++){
        cout << *(arr + i) << endl;
        // arr ++ ;illegal
    }
}

void pointer_to_pointer(){

    int a = 10;
    int *p;
    p = &a;

    cout << *p << endl; // Dereferencing

    int **q = &p;
    cout << *q << endl;
    cout << **q << endl;
    
}

int main(){

    // int a = 10;
    // int* aptr = &a;

    // cout << aptr << endl;
    // cout << *aptr << endl;

    // *aptr = 54866857;
    // cout << *aptr << endl;


    // // Pointer arithmet
    // // ++,--,+,-
    // aptr++;
    // cout << aptr << endl; // 0x60ff08 to 0x60ff0c   i.e,8 to c 8+4 = 12 i.e, 12

    pointer_array();
    cout << endl;

    pointer_to_pointer();
    cout << endl;

    return 0;
}