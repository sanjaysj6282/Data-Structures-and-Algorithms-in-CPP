#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Vectors(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i = 0; i < v.size();i++){
        cout << v[i] << endl;
    }

    vector<int>::iterator it;
    // iterator is a pointer
    for(it = v.begin();it != v.end();it++)
        cout << *it << endl;

    // Easiest
    // "auto" keyword -- to find the data type own its own according to intialising
    // Like(python) -- for i in v
    for(auto element:v)
        cout << element << endl;

    // pop element at the end
    v.pop_back();  // 1 2

    // no of times, element 
    vector<int> v2 (3,50);   // 50 50 50

    // Swap elements 
    swap(v,v2);

    for(auto element:v)
        cout << element << endl;

    // To sort
    sort(v.begin(),v.end());

    cout << endl;
}

int main(){

    Vectors();

    return 0;
}