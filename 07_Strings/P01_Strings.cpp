#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    
 // Declaration

    // Type 1
    string str;
    cin >> str;
    cout << str << endl;

    // Type 2
    string suku(5,'n');
    cout << suku;

    // Type 3
    string g = "dhjvfdb"; // No space

    // Type 4(For space in between)
    string str2;
    getline(cin,str2);
    cout << str2 << endl;


 // For Concatenation

    string s1 = "fam";
    string s2 = "ily";
    //Type 1
    string s3 = s1+s2;

    //Type 2
    s3 = s1.append(s2);


    // Accessing characters
    cout << s1[1];


 // Clears everything in f 
    string f = "fhsdgdfxngtsrnzfezf sfrdt";
    f.clear(); 

 // Compare two strings 
    string e1 = "abc";
    string e2 = "xyz";
    cout << e2.compare(e1) << endl;

    if(!e2.compare(e1)){  // Not true not 0
        cout << "Strings are equal" << endl; 
    }

 // string empty
    e2 = " ";
    if(e2.empty())
        cout << "'vsf";

 // erase
    string hg = "nincompop";
    hg.erase(3,2); // (index,number of elements) 
    cout << hg << endl;

 // Find
    cout << hg.find("pop") << endl;

 // Insert
    string k = "lol";
    hg.insert(2,k); // (index,"   " or k)
    cout << hg  << endl; 

 // Length
    cout << k.size() << endl;
    cout << k.length() << endl;

    for (int i = 0; i < k.length();i++){
        cout << k[i] << endl;
    }

 // Substring
    string s = hg.substr(2,4); // (index, number of elements)
    cout << s << endl;

 // Conversion
    string o = "5997ahjj";
    int x = stoi(o); // string to integer
    cout << x+11 << endl;
    
    cout << to_string(x) + "2" << endl; // int to string

 // Sort
    string us = "gqwertyuiopasdfghjklzxcvbnmdhfdgfdddddddddhj";
    sort(us.begin(),us.end()); //  uses <algorithm>
    cout << us << endl;

    return 0;
}