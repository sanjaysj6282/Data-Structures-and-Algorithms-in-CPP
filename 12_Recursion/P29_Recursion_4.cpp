#include <iostream>
using namespace std;

// VIMP
// Watch video first
// String permutation
// "ans" to store each permuted answer
void permutation(string s, string ans){

    if(s.length() == 0){
       cout << ans << endl;
       return; 
    }

    for(int i = 0;i < s.length();i++){
        char ch = s[i];
        // To get concatenated substring before and after s[i]
        string ros = s.substr(0,i) + s.substr(i+1); // (Starting,length)  

        permutation(ros,ans+ch);
    }
}

int countPath(int s,int e){

    if(s == e){
        return 1;
    }

    if(s > e){
        return 0;
    }

    int count = 0;
    for(int i = 1; i <= 6;i++){ // There are 6 no.s in a dice
        count += countPath(s+i,e);
    }
    return count;
}

int countPathMaze(int n,int i,int j){
    
    if(i == n-1 && j == n -1 ){
        return 1;
    }

    if(i >= n || j >= n){
        return 0;
    }

    // At each coordinate we can go both X and Y direction So we add
    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);
}

int main(){

    permutation("abc","");

    cout << countPath(0,3) << endl;

    cout << countPathMaze(3,0,0) << endl;

    return 0;
}