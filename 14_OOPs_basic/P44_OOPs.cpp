// One of MostIMP Concept

// Not Clear --->Refer

// Refer notes to make concept perfect
// Refer more notes other than AC

#include <iostream>
using namespace std;

class student{
    // name , age .... "Data Members"

    // To make the data members public
    // i.e, to use it outside the class
    // By default it is private
    
    public:
    string name;
    int age;
    bool gender;

    void printInfo(){
        cout << name << endl;
        cout << age << endl;
        cout << gender << endl;
        cout << endl;
    }
};

int main(){
    

    // student a;     Similar to giving name to datatype , eg int a;
    // a.name = 'Urvi';
    // a.age = 20;
    // a.gender = 1;

    student arr[3];
    for(int i = 0; i < 3;i++){
        cin >> arr[i].name;
        cin >> arr[i].age;
        cin >> arr[i].gender;
    }

    for(int i = 0; i < 3;i++){
        arr[i].printInfo();
    }

    return 0;
}