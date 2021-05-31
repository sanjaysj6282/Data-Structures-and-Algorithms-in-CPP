#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    // Declaring map of key and value as int datatype
    map<int, int> m;
    // at key = 8 we initialise value = 2
    // Similar to array (in terms of accessing)
    m[8] = 2;
    cout << m[8] << "\n ";

    return 0;
}
 