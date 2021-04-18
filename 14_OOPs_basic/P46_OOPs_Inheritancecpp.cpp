#include <iostream>
using namespace std;

/*
      Different typesof Inheritance
      
    1 Single inheritance
    2 Multiple Inheritance
    3 Multi level inheritance
    4 Hybrid Inheritance
    5 Hierarchical Inheritance
    
*/



// Single inheritance
// Class B publically inherits from A i.e, B inherits public and protected items from A

class A{
    public:
        void func(){
            cout << "Inherited" << endl;
        }
};
class B : public A{

};

/*
// Multiple Inheritance
class A{
    public:
        void Afunc(){
            cout << "Func A\n" << endl;
        }
};
class B{
    public:
        void Bfunc(){
            cout << "Func B\n" << endl;
        }
};
class C : public A,public B{
    // U can include more attributes
};

main
C c;
c.Afunc();
c.Bfunc();
*/

/*
// Multilevel inheriatance

class A{
    public:
        void Afunc(){
            cout << "Func A\n" << endl;
        }
};
class B : public A{
    public:
        void Bfunc(){
            cout << "Func B\n" << endl;
        }
};
class C : public B{
    // U can include more attributes
};
*/



int main(){

    B b;
    b.func();

    return  0;
}