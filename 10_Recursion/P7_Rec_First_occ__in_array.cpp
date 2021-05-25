#include <iostream>
using namespace std;

int firstocc(int arr[], int n,int i,int key){
    // Base condition 
    if(i == n)
        return -1;
    
    if(arr[i] == key)
        return i;
    
    return firstocc(arr,n,i+1,key);
}

// Or for lastocc
// i = n-1 initially
// then i--
int lastocc(int arr[], int n,int i,int key){

    // Base condition
    if(i == n)
        return -1;

    int restArray = lastocc(arr,n,i+1,key);
    if(restArray != -1)
        return restArray;
    
    if(arr[i] == key)
        return i;
    
    return -1;
}

int main(){

    cout << firstocc(arr,5,0,5) << endl;
    // i is for indexing
    cout << endl;

    cout << lastocc(arr,5,0,-1) << endl;
    cout << endl;
    return 0;
}