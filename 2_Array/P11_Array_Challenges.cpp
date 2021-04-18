#include <iostream>
using namespace std;

//Max till i
int Max_till_i(int array[],int n){

    int Max = -199999;
    for (int i = 1;i < n;i++){
        if (Max < array[i]){
            Max = array[i];
        }
    }
    return Max;
}

//Sum of each Subarray
void Sum_Subarrays(int array[],int n){

    int curr = 0;
    for(int i = 0;i < n;i++){
        curr = 0;
        for (int j = i; j < n;j++){
            curr += array[j];
            cout << curr << endl;
        }        
    }
}


// VIMP

// Google kickstart
// Longest Arithmetic Subarray
// For solution refer P - 139

void Longest_Arithmetic_Subarray(int a[],int n){

    int ans = 2;
    int pd = a[1] - a[0];
    int j = 2;
    int curr = 2;

    while(j < n){

        if( pd == a[j] - a[j-1]){
            curr++;
        }

        else{
            pd = a[j] - a[j-1];
            curr = 2;
        }
        ans = max(ans,curr);
        j++;


    }
    cout << ans << endl;
}

// VIMP

// Google kickstart
// Record Breaker
// For solution refer P - 142

void Record_Breaker(){

    int n;
    cout << "Enter the number of elements to be entered ";
    cin >> n;

    int a[n+1];
    a[n] = -1;

    cout << "Enter the elements to the new array " << endl;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    // VIMP
    // Corner case
    //    
    if(n == 1){
        cout << "1" << endl;                                        
    }

    // Starting of difference between mine and their code
    int ans = 0;
    int mx = -1;

    for(int i = 0;i < n;i++){

        if(a[i] > mx && a[i] > a[i+1]){

            ans++;
        }
        mx = max(mx,a[i]);
    }
    cout << "Record Breaker is " << ans;

}




int main(){

    int n;
    cout << "Enter the number of elements to be entered ";
    cin >> n;

    cout << endl;

    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    cout << endl;

    cout << "The Biggest element is" << Max_till_i(arr,n);
    cout << endl;

    cout << "Sum of subarrays" << endl;
    Sum_Subarrays(arr,n);
    cout << endl;

    cout << "Longest_Arithmetic_Subarray" << endl;
    Longest_Arithmetic_Subarray(arr,n);
    cout << endl;

    cout << "Record_Breaker" << endl;
    Record_Breaker();
    cout << endl;
}