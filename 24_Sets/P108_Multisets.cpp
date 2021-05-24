#include <iostream>
#include <set>
using namespace std;

// Difference is it can contain duplicates
 

int main(){
    multiset<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(5 );

    // Printing the element in the set
    for(auto i:s)
        cout << i << " ";
    cout << "\n";

    // Size of set
    cout << s.size() << endl;

    // Erase one 3
    s.erase(s.find(3));
    for(auto i:s)
        cout << i << " ";
    cout << "\n";

    // Erase all 3
    s.erase(3);
    for(auto i:s)
        cout << i << " ";
    cout << "\n";

    return 0;
}
