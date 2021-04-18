#include <iostream>
using namespace std;

int Factorial(int Num){
    int Factorial;
    Factorial = Num;
    for (int i = Num - 1;i >= 2;i--){
        Factorial = Factorial * i;

    }
    return Factorial;
}

bool Is_Reverse(int Num){
    int Rev_Number;
    Rev_Number = 0;

    int n = Num;
    while (Num >0){
        int Rem ;
        Rem = Num % 10;
        Rev_Number = Rev_Number * 10 + Rem;
        Num = Num/10;
    
    }
    cout << "The Reversed number is";
    cout << Rev_Number << endl;

    if (Rev_Number == n){
        return 1;
    }
    else{
        return 0;
    }
}
void Is_Amstrong(int Num){
    int n = Num;
    int Amstrong = 0;
    while (Num > 0){
        int rem = Num % 10;
        Amstrong = Amstrong * 10 + rem * rem * rem;
        Num = Num/10;
    }
    if (Amstrong == n){
        cout << "Hurray!" << "Its an Amstrong number" << endl;

    }
    else {
        cout << "Its not an Amstrong number" << endl;

    }
    return;
}

void Fibonacci_Series(int number){

    // Complexity in terms of code can be reduced

    int a = 0;
    int b = 1;
    int sum;
    cout << a << " " << b << " ";
    while (number > b)
    {
        sum= a+b;
        a = b;
        b = sum;
        if (b > number){
            break;
        }

        else{
        cout << b << " ";
        }
    }
    

}

int main(){
    cout << "Enter a Number" << endl;
    int Number;
    cin >> Number;

    cout << endl;

    cout << Factorial(Number) << endl;

    if (Is_Reverse(Number)){
        cout << "Hurray!" << endl << "We got the same number" << endl;
    }
    else{
        cout << "We did not get the same number" << endl;
    }

    cout << endl;

    Is_Amstrong(Number);

    cout << endl;

    Fibonacci_Series(Number);

    cout << endl;

    return 0;
}



/*
#include <iostream>
using namespace std;
int add(int num1, int num2){
 int sum = num1 + num2;
 return sum;
}
int main()
{
 int a,b;
 cin>>a>>b;
 cout<<add(a,b)<<endl;
 return 0;
}
*/


/*
#include <iostream>
using namespace std;
void display(int a){
 cout<<a<<endl;
 return;
}
int main()
{
 int a;
 cin>>a;
 display(a);
 return 0;
}

 */