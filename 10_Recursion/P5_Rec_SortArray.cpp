#include <iostream>
using namespace std;

// IMP
bool sorted_rec(int arr[],int n){
    if(n == 1)
        return true;

    bool restArray = sorted_rec(arr+1,n-1);// pointer goes to arr[i] --> arr[i+1]
    return (arr[0] < arr[1] && restArray); // If both are true return "true"
    // OR
    /* 
    if(arr[0] < arr[1] && restArray)
         return true;
    */
}

int main(){

    int arr[] ={1,2,3,5,-1};
    cout << sorted_rec(arr,5) << endl;
    cout << endl;

    return 0;
}