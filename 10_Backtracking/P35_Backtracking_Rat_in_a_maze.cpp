// VIMP
// Hard --- Backtracking generally....

// Look video for Instructions

#include <iostream>
using namespace std;

// 1 represents path of rat from source to destination

// To check wheather movement in a particular direction possible or not
bool isSafe(int **arr,int x,int y,int n){

    if(x<n && y<n && arr[x][y]==1)
        return true;
    return false;    
}

bool ratinMaze(int **arr,int x,int y,int n,int **solArr){

    if(x == n-1 && y == n-1){
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        solArr[x][y] = 1;
        if(ratinMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solArr)){
            return true;
        }
        // VIMP
        solArr[x][y] = 0;      //backtracking
        return false;
    }
    return false;
}

int main(){

    int n;
    cin >> n;

    // Memory allocation through Dynamic memory allocation
    // Declaring dynamic array
    int** arr = new int*[n];

    // Each element in a 1 D array is made into a array
    // & thereby a 2D array
    for(int i = 0; i < n; i++)
        arr[i] = new int[n];
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }

    int** solArr = new int*[n];
    for(int i = 0; i < n; i++){
        solArr[i] = new int[n];
        for(int j = 0; j < n; j++){
            solArr[i][j] = 0;
        }
    }

    cout << endl;
    if(ratinMaze(arr,0,0,n,solArr)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
