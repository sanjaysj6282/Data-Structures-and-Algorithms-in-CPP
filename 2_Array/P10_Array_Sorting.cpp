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
    for(int i = 0;i < n;i++){
        cout << arr[i] << ",";
    }
    cout << "]";

    cout << endl;

}

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
    for(int i = 0;i < n;i++){
        cout << arr[i] << ",";
    }
    cout << "]";

    cout << endl;

}

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
    for(int i = 0;i < n;i++){
        cout << arr[i] << ",";
    }
    cout << "]";

    cout << endl;

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


    Selection_sort(arr,n);
    Bubble_sort(arr,n);
    Insertion_sort(arr,n);

}