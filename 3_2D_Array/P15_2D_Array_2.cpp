#include <iostream>
using namespace std;

void Matrix_Transpose(int n, int m){
    
    int arr[n][m];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }

    int temp;
    for(int i = 0;i < n;i++){
        for(int j = i;j < m;j++){
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix_Multiplication(){

    int n1,m1,n2,m2;

    cin >> n1 >> m1 >> n2 >> m2;

    int a1[n1][m1];
    int a2[n2][m2];
    int a3[n1][m2];

    for(int i = 0;i < n1;i++){
        for(int j = 0;j < m1;j++){
            cin >> a1[i][j];
        }
    }
    for(int i = 0;i < n2;i++){
        for(int j = 0;j < m2;j++){
            cin >> a2[i][j];
        }
    }

    if(n2 == m1){
        cout << "Matrix multiplication is possible" << endl;

        for(int i = 0;i < n1;i++){
            for(int j = 0;j < m2;j++){
                for(int k = 0;k < n2;k++){
                   a3[i][j] += a1[i][k] * a2[k][j];
                }
            }
        }

        for(int i = 0;i < n1;i++){
            for(int j = 0;j < m2;j++)
            // for a loop containing single statement doesnt need a {}
                cout << a3[i][j] << " ";
            cout << endl;
        }


    }
    else{
        cout << "Matrix multiplication not possible";
    }
}

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

    Matrix_Transpose(n,m);
    Matrix_Multiplication();
    Matrix_search(n,m);
}

