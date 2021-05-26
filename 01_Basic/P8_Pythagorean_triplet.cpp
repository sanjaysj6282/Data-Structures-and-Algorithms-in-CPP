#include <iostream>
using namespace std;

bool PythagorianTriplet(int x,int y,int z){
    int Max;
    Max = max(x,max(y,z));
    if (Max == x){
        if (x * x == y * y + z * z)
            return true;
        
        else
            return false; 
    }
    else if (Max == y){
        if (y * y == x * x + z * z)
            return true;
        else
            return false;
    }
    else if (Max == z){
        if (z * z == x * x + y * y)
            return true;
    
        else
            return false;
    }
    
}

int main(){
    int x,y,z;
    cout << "Enter 3 Numbers" << endl;
    cin >> x >> y >> z;
    
    if (PythagorianTriplet(x,y,z)){
        cout << "It's a pythagorian Triplet" << endl;
    }
    else{
        cout << "It's not a pythagorian Triplet" << endl;
    }

    cout << endl;

    return 0;
}