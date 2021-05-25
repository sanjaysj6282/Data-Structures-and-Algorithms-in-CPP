// Refer videos for further clarity
// ALso refer other notes

#include <iostream>
using namespace std;

// Functon overloading
class sanjay{
    public:
        void fun(){
            cout << "I'm a function with no arguments" << endl;
        }
        void fun(int x){
            cout << "I'm a function with int arguments" << endl;
        }
        void fun(double x){
            cout << "I'm a function with double arguments" << endl;
        }
};


// Operator Overloading 
class Complex{
    int real,imag;
    public:
        //Put r,i to its default value || My explanation --> For c3 defining we need a default value for its imag and real part
        Complex(int r = 0,int i = 0){
            real = r;
            imag = i;
        }
        // IMP
        // Confusing
        // operator --> Keyword
        // +/-/*  --> Operator which is to be overloaded
        // &obj by reference
        Complex operator + (Complex const &obj){
            Complex res;
            res.imag = imag +obj.imag;
            res.real = real + obj.real;
            return res;
        }

        void display(){
            cout << real << " + i" << imag << endl;
        }
};

// Run time Polymorphism
// Virtual functions
class base{
    public:
        // Virtual is not executed immediately but other
        virtual void print(){
            cout << "This is the base class's print function" << endl;
        }
        void display(){
            cout << "This is the base class's display function" << endl;
        }
};
class derived: public base{
    public:
        void print(){
            cout << "This is the derived class's print function" << endl;
        }
        void display(){
            cout << "This is the derived class's display function" << endl;
        }
};

int main(){

    // FO
    sanjay s;
    s.fun();
    s.fun(546);
    s.fun(4.25);
    cout << endl;

    // OO
    Complex c1(12,7);
    Complex c2(6,7);
    Complex c3 = c1+c2;
    c3.display();
    cout << endl;

    // VF
    base *baseptr; // base class pointer
    derived d;     // derived class object
    baseptr = &d;  // Put address of derived class in baseptr

    // Since it is  a pointer "." operator is not used but "-->"
    baseptr  -> print();
    baseptr  -> display();

    
    return 0;
}