#include <iostream>
#include <unordered_set>
using namespace std;

/*

1. Contains unique elements
2. Implementation using  Hashing
3. Elements are NOT in sorted order;
4. Random access is not possible, i,e, one can't get i'th 
   element in O(1)
5. Present in   #include<unordered_set>   header file

*/
/*
    Time Complexities

    Insertion : O(1) in avg case, O(N) in worst case
    Deletion  : O(1) in avg case, O(N) in worst case
    Lower/Upper_Bound: NA

*/
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(5);

    // Printing the element in the set
    for(auto i:s)
        cout << i << " ";
    cout << "\n";

    // Size of set
    cout << s.size() << endl;

    // Erase;
    s.erase(s.begin());
    for(auto i:s)
        cout << i << " ";
    cout << "\n";

    return 0;
}
