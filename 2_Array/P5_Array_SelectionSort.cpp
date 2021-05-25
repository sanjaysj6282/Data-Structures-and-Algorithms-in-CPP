#include <iostream>
using namespace std;

//Selection Sort
void Selection_sort(int arr[],int n){

    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
           if(arr[j] < arr[i]){
               int temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           } 
        }
    }

    cout << endl;

    cout << "[";
    for(int i = 0;i < n;i++)
        cout << arr[i] << ",";
    cout << "]";

    cout << endl;

}

int main(){

    int n;
    cout << "Enter the number of elements to be entered ";
    cin >> n;

    cout << endl;

    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    Selection_sort(arr,n);
}