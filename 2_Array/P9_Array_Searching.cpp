#include <iostream>
using namespace std;

int Linear_Search(int array[],int item,int n){

    for (int i = 0;i < n;i++){
        if(item == array[i]){
            return i;
        }

    }
    return -1;

}

int Binary_Search(int array[],int item,int n){
        
    int s = 0;
    int e = n;
    while (s <= e){
        int mid = (s+e)/2;

        if (array[mid] == item){
            return mid;
        }
        else if (array[mid] >= item){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return -1;

}



int main(){

    cout << "Enter the number of elements to be entered in the list " << endl;
    int n;
    cin >> n;

    int array[n];

    for (int i = 0;i < n;i++){
        cin >> array[i];
    }

    cout << "Enter the element to be searched " << endl;
    int item;
    cin >> item;

    int Index;
    Index = Linear_Search(array,item,n);  
    cout << "Element found at Index " << Index << endl;

    Index = Binary_Search(array,item,n);
    cout << "Element found at Index " << Index << endl;

    return 0;
}