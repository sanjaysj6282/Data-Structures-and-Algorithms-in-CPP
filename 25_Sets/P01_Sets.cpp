#include <iostream>
#include <set>
using namespace std;
/*
1. Contains unique elements
2. Implementation using balanced BST
3. Elements are in sorted order;
4. Random access is not possible, i,e, one can't get i'th 
   element in O(1)/ O(logN)
5. Present in   #include<set>   header file

*/
int main(){
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(5);

    // Printing the element in the set
    for(auto i:s)
        cout << i << " ";
    cout << "\n";

    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << "\n";
    
    // Print in reverse
    for (auto i = s.rbegin(); i != s.rend(); i++)
        cout << *i << " ";
    cout << "\n";

    // Size of set
    cout << s.size() << endl;

    // Erase;
    s.erase(1);
    s.erase(s.begin());

    for(auto i:s)
        cout << i << " ";
    cout << "\n";


    // Custom comparator
    set<int, greater<int>> s1;

    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(5);

    cout << *s.lower_bound(2) << " ";
    cout << *s.lower_bound(3) << " ";
    cout << *s.upper_bound(3) << " ";
    cout << (s.upper_bound(5)==s.end()) << "\n";

    return 0;
}
