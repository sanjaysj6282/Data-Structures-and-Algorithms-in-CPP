#include <iostream>
using namespace std;

void Insertion_sort(int arr[],int n){

    for(int i =  1; i < n;i++){
        int current = arr[i];
        int j = i-1;
        while (arr[j] > current && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

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

    Insertion_sort(arr,n);

}