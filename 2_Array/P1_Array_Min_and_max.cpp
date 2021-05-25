#include <iostream>
using namespace std;

void Max_and_Min(){

    cout << "Enter the number of elements to be entered in the list " << endl;
    int n;
    cin >> n;

    int array[n];

    for (int i = 0;i < n;i++){
        cin >> array[i];
    }

    int Max = array[0]; 

    for (int i = 0;i < n;i++){
        if(Max <= array[i]){     // We can combine to 1 for loop for finding amx and min
            Max = array[i];      //We can also use max function   
        }
    }

    int Min = array[0];

    for (int i = 0;i < n;i++){
        if(Min >= array[i]){
            Min = array[i];
        }
    }

    cout << "The biggest element is " << Max <<endl;
    cout << "The smallest element is " << Min <<endl;

}

int main(){
    
    Max_and_Min();

    return 0;
}