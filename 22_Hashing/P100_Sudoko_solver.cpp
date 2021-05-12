#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define vi vector<int> 
#define mi map<int, int>
#define pi pair<int, int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

// IMP
// Hard --> Only hard part is its Data structure choosing Logic is simple 
// Recursion(Backtracking) and Hashing
/*
    Algorithm
    Steps
1.  Start from (0,0) to (8,8)
2.  Try out allvalid combinations
3.  ans = false, currently at (x, y)
4. a) if
        ans=already filled, move to next block
   b) else
        for(numbers = 1 to 9)
            if you can place number at (x, y)
                ans = ans or place no. at (x, y) and move to next block
*/

void helper(int r, int c, vector<vector<char>> &a, map<pi,mi> mp, vector<mi> row, vector<mi> col){
    // base case
    if(r == 9){
        for(auto it : a){
            for(auto i : it)
                cout << i << " ";
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    // If col finishes then we go to next row col 0
    if(c == 9){
        helper(r+1,0,a,mp,row,col);
        return;
    }

    // No is already present
    if(a[r][c] != '.'){
        helper(r,c+1, a,mp,row,col);
        return;
    }

    // Logic part
    // MVP
    for(int i=1;i<=9;i++){
        // For acessing each grid
        int rw=r/3, cl=c/3;
        // IF ith no is not present in curr "grid", "row" and "col" 
        if(!mp[{rw, cl}][i] and !row[r][i] and !col[c][i]){ 
            // Just making it true
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            // Putting value "i" in a[row][col]
            a[r][c] = i+'0';

            helper(r,c+1, a, mp,row,col);

            // backtracking
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}

void solveSudoku(vector<vector<char>> &a){
    // Its to check a value is present in a particular grid or not
    map<pi, mi> mp; // pi denotes "grids" as (x, y)
    // Its to check a value is present in a particular Row/Coloumn or not
    vector<mi> row(9); 
    vector<mi> col(9); 

    rep(i, 0, 9){
        rep(j, 0, 9){
            if(a[i][j] != '.'){
                // True/1 to symbolise value is present
                // [i/3][j/3] to find the grid
                mp[{i/3, j/3}][a[i][j]-'0'] = 1;
                row[i][a[i][j]-'0'] = 1;
                col[j][a[i][j]-'0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

int main(){
    vector<vector<char>> sudoko = {
        {'5', '3', '.', '.', '7', '.' , '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5' , '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.' , '.', '.', '.'},
        {'8', '.', '.', '.', '6', '.' , '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3' , '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.' , '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.' , '2', '8', '.'},
        {'.', '.', '.', '.', '1', '9' , '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.' , '.', '7', '9'}
    };
    solveSudoku(sudoko);

    return 0;
}