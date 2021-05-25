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

int main(){

    permutation("abc","");

    return 0;
}