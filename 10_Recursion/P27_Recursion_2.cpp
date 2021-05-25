#include <iostream>
using namespace std;

// IMP
bool sorted_rec(int arr[],int n){

    if(n == 1){
        return true;
    }

    bool restArray = sorted_rec(arr+1,n-1);// pointer goes to arr[i] --> arr[i+1]
    return (arr[0] < arr[1] && restArray); // If both are true return "true"
    // OR
    /* 
    if(arr[0] < arr[1] && restArray){
         return true;
    }
    */
}

void dec(int n){

    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    dec(n-1);  
}

// VIMP --> Reversion concept
// understand the difference between inc & dec
void inc(int n){

    if (n == 0){
        return;
    }
    inc(n-1);
    cout << n << endl;
}

// Imp
int firstocc(int arr[], int n,int i,int key){
    
    // Base condition 
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}

// Or for lastocc
// i = n-1 initially
// then i--
int lastocc(int arr[], int n,int i,int key){

    // Base condition
    if(i == n){
        return -1;
    }
    int restArray = lastocc(arr,n,i+1,key);
    if(restArray != -1){
        return restArray;
    }
    if(arr[i] == key){
        return i;
    }
    return -1;
}

int main(){

    int arr[] ={1,2,3,5,-1};
    cout << sorted_rec(arr,5) << endl;
    cout << endl;

    int n;
    cin >> n;
    dec(n);
    cout << endl;
    
    inc(n);
    cout << endl;

    cout << firstocc(arr,5,0,5) << endl;
    // i is for indexing
    cout << endl;

    cout << lastocc(arr,5,0,-1) << endl;
    cout << endl;
    return 0;
}