// Real value type
#include <iostream>
using namespace std;

int main(){
    int target=100;
    double L=0;
    double R=100;
    // Here we dont do l,r = mid +/- 1
    // Since we are not dealing with integers 
    while (R-L > 1e-9){
        double mid=L+(R-L)/2;
        if(mid*mid<target) // "<="" also correct
            L=mid;         // Since for very small no's
        else
            R=mid;     
    }
    cout << L+(R-L)/2 << endl;
    

    return 0;
}