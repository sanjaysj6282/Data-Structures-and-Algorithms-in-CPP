#include <iostream>
using namespace std;

// Imp
void SpiralOrder_Matrix_Traversal(int n, int m){

    // Input 2D array
    int arr[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }

    int row_start = 0,row_end = n-1,column_start = 0,column_end = m-1;
    while(row_start <= row_end && column_start <= column_end){

        // for row start
        for(int col = column_start;col <= column_end;col++){
            cout << arr[row_start][col] << " ";
        }
        row_start++;

        // for column end
        for(int row = row_start;row <= row_end;row++){
            cout << arr[row][column_end] << " ";
        }
        column_end--;

        // for row end
        for(int col = column_end;col >= column_start;col--){
            cout << arr[row_end][col] << " ";
        }
        row_end--;

        // for colummn end
        for(int row = row_end;row >= row_start;row--){
            cout << arr[row][column_start] << " ";
        }
        column_start++;
    }
}

int main(){

    int n;
    int m;
    cin >> n >> m;
    int arr[n][m];
    
    // Input 2D array
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }
    }

    cout << "\n";

    // Output 2D array
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    // Search in a matrix
    int item;
    cin >> item;
    int t = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == item){
                cout << "Element found at ";
                cout << i << " " << j << " " << endl;
                t = 1;
            }
        }
    }
    if(t = 0){
        cout << "Element not found" << endl;
    }
    cout << "\n";

    SpiralOrder_Matrix_Traversal(n,m);
    cout << "\n";


    return 0;
}