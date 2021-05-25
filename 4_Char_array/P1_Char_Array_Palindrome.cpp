#include <iostream>
#include <climits>
using namespace std;

void Palindrome(){

    int n; 
    cin >> n;

    char arr[n+1];
    cin >> arr;

    bool check = 1;

    for(int i = 0;i < n;i++){
        if(arr[i] != arr[n -1 - i]){
            check = 0;
            break;
        }
    }

    if(check){
        cout << arr << "  Is a palindrome" << endl;
    }
    else{
        cout << arr << "  Is not a palindrome" << endl;
    }

    
}

int main(){
    char arr[100] = "apple";
    int i = 0;

    cout << arr << endl;;

    while(arr[i] != '\0'){
        cout << arr[i] << endl;
        i++;
    }

    Palindrome();


    return 0;
}