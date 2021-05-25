#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void conversion(){

 // M1
    string str = "sxgfchvdccchj";
    // cout << 'a' - 'A' << endl;


    // converts into uppercase
    for(int i = 0; i < str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -=32;
        }
    }
    cout << str << endl;
    //converts to lower case
    for(int i = 0; i < str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] +=32;
        }
    }
    cout << str << "\n";

 // M2--Using functions
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << "\n";

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << "\n"; 
}


int main(){

    conversion();

    return 0;
}
