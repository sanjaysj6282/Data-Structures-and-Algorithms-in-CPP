#include <iostream>
using namespace std;

int main()
{
    char Value;
    bool Lcase,Ucase;


    cout<<"Enter an alphabet"<<endl;
    cin>>Value;

    Lcase = (Value == 'a'||Value == 'e'||Value == 'i'||Value == 'o'||Value == 'u');
    Ucase = (Value == 'A'||Value == 'E'||Value == 'I'||Value == 'O'||Value == 'U');

    if(Lcase||Ucase)
    {
        cout<<"It's a Vowel"<<endl;
    }
    
    else
    {
        cout<<"It's a Consonant"<<endl;
    }
    
    return 0;
}


// Apni College
/*#include <iostream>
using namespace std;
int main()
{
 char c;
 int isLowercaseVowel, isUppercaseVowel;
 cout << "Enter an alphabet: ";
 cin >> c;
 isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
 isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
 if (isLowercaseVowel || isUppercaseVowel)
 {
 cout << c << " is a vowel.";
 }
 else
 {
     cout << c << " is a consonant.";
 }
 return 0;
}*/