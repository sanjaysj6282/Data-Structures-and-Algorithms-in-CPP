#include <iostream>
using namespace std;

// IMP
void reverse(string s){
    if(s.length() == 0) // Base case
        return;

    // Similar to "Print in increasing order"
    string ros = s.substr(1); // Substring after the first element in the string 
    reverse(ros);
    cout << s[0]; // O th element is VIMP

}

int main(){

    string s = "Binod";
    reverse(s);

    return 0;
}