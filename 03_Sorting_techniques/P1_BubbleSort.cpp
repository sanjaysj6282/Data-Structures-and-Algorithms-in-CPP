#include <iostream>
using namespace std;

//Bubble Sort
void Bubble_sort(int arr[],int n){

    int counter = 1;
    while (counter < n){
        for(int i = 0;i < n-counter;i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
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

    Bubble_sort(arr,n);
}