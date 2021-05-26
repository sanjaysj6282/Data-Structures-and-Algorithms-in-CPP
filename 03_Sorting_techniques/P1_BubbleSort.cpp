#include <iostream>
using namespace std;

// Bubble Sort
/*     Main Idea
  Repeatedly swap 2 adjacent elent if they 
  are in wrong order

  After complete swaping by iterating once we get "largest" element in final position 
  So we've to n-1 iterations of such to get Sorted array
  but keep in mind that on each iteration we need to reduce the no of iterations by 1
  i.e, 1st iteration : n-1
       2nd ite       : n-2
       n-1 iter      : n-i (in for loop) 
*/
void Bubble_sort(int arr[],int n){

    int counter = 1; // To manage n-1 executions
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