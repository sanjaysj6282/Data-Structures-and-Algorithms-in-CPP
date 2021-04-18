#include <iostream>
using namespace std;

int main()
{
    int  m,n;
    cout << "Enter the number of Rows \n";
    cin >> m;
    cout << "Enter the number of Coloumns \n";
    cin >> n;
    cout << "Hello \n";
    cout << m << endl;
    cout << n << endl;

//  Rectangle
    for (int i = 1; i <= m ; i++){
        for (int j = 1 ; j <= n ; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

//  Hollow Rectangle
    for (int i = 1; i <= m;i++){
        for (int j = 1;j <= n;j++){
            if (i == 1 || j == 1 || i == m || j ==n){
                cout << "*";
            }
            else{
                cout << " ";
            }

        }
        cout << endl;
    }


    cout << endl;

//  Pyramid
//  For different Pyramids
//  Find a constant pattern

    for (int i = 1;i <= m;i++){
        for (int j = 1;j <= i;j++){
            cout << "*";
        }
        cout << endl;
    }

//  Pyramid (Number)-Floyd's Triangle
    int k;
    k=1;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= i;j++){
            cout << k << " " ;
            k++;
        }
        cout << endl;
    }

/*  Butterfly Pattern question (VIMP)

   *             *               *             *
   * *         * *               * *         * *     
   * * *     * * *               * * *     * * *  
   * * * * * * * *       =====   * * * * * * * *
   * * * * * * * *               ---------------       
   * * *     * * *               * * * * * * * *
   * *         * *               * * *     * * *             
   *            *                * *         * *
                                 *             *
   
   Look code carefully
   Problem approach
   Generate formula for complex problem
   
   Steps
  1 Take a number such as 4
  2 Analyse the pattern
    (For such problems first)
  3 Find Rows     - 1 to n
  4      Coloumns -  "     (Square)
  5 
  5 Divide it into 2 - 1st part just needs to be reversed
  6 "*"        = No of rows
  7 " "(Space) = 2*n - 2*i (i.e, Row number)
  8 We find the row functionality is reversing So we reverse the Row loop(i.e, n to 1)
*/
    for (int i = 1;i <= n;i++){
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        
        int space;
        space = 2*n -2*i;
        for (int j = 1; j <= space; j++){
            cout << " ";
        } 

        for (int j = 1;j <= i;j++){
            cout << "*";
        }
        cout << endl;

    }

    for (int i = n;i >= 1;i--){
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        
        int space;
        space = 2*n -2*i;
        for (int j = 1; j <= space; j++){
            cout << " ";
        } 

        for (int j = 1;j <= i;j++){
            cout << "*";
        }
        cout << endl;

    }


    return 0;
}

