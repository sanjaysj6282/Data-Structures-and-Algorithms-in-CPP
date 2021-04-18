#include <iostream>
using namespace std;

class A{
    public:
        int a;
        void funcA(){
            cout << "dfds" << endl;
        }
    private:
        int b;
        void funcB(){
            cout << "sf" << endl;
        }
    protected:
        int c;
        void funcC(){
            cout << "jh" << endl;
        }
};

int main(){

    A obj;
    obj.funcA();
    // obj.funcB();
    // obj.funcC();

    return 0;
}