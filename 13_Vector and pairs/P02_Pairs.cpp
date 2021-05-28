#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// custom comparators
// To sort a vector in ascending order
bool myCompare(pair<int,int> p1 , pair<int,int> p2){
    return p1.first<p2.first;
}

void Pair(){

    pair <int,char> p;
    p.first = 3;
    // IMP
    // There should be only a single char in second eg.  'f'  but not like  'jhf' and it should be in single quotes
    p.second = 'f';

    int arr[] = {10,16,7,14,5,3,12,9};
    // Declaration of vector of pairs
    vector < pair<int,int> > v;

    // To find size of array
    // Size of arr = (no.of elements in array) X size of each element ,here 8 X 4(size of int) 
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0]));i++){
        // pair <int,int> p;
        // p.first = arr[i];
        // p.second = i;
        // Then push p in vector

        // OR
        v.push_back(make_pair(arr[i],i));
    }

        sort(v.begin(),v.end(),myCompare);

        for(int i = 0;i < v.size();i++)
            arr[v[i].second] = i;   

        for(int i = 0;i < v.size();i++)
            cout << arr[i] << " ";
        cout << endl; 
}
int main(){

    Pair();

    return 0;
}