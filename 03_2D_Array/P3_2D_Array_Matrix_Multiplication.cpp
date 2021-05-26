#include <iostream>
using namespace std;

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


int main(){

    int n,m;
    cin >> n >> m;

    Matrix_Multiplication();

}

