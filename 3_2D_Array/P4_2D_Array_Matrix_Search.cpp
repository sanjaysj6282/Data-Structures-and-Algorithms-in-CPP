#include <iostream>
using namespace std;

void Matrix_search(int n, int m){

    int item;
    cin >> item;
    bool flag = false;

    int arr[n][m];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }

    int row = 0, column = m -1;
    while(row < n && column >= 0){
        if(item == arr[row][column]){
            flag = true;
            break;
        }
        else if(item > arr[row][column]){
            row++;
        }
        else{
            column--;
        }
    }

    if(flag){
        cout << "Element found" << endl;
    }
    else{
         cout << "Element not found" << endl;
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    Matrix_search(n,m);
}