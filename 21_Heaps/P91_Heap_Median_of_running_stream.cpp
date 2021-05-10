#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for(int i=0; i<b; i++);

// VIMP --> Placement

/*
Optimized approach (Using heaps)

1. Create two heaps. 
   One MaxHeap to maintain elements of lower half and
   One MinHeap to maintain elements of higher half at any instant.

2. For every newly read element, insert it into either MaxHeap or MinHeap
   and calculate the median based on the following conditions:
    ● If the size of MaxHeap is greater than the size of MinHeap and the
      element 
      a. Is greater than the top element of the MaxHeap then pop the
         top element from MaxHeap and insert into MinHeap and insert the
         new element to MaxHeap } 
      b. else  insert the new element to MinHeap .
         
    Calculate the new median as the average of top elements of both
    MaxHeap and MinHeap.

    ● If the size of MaxHeap is less than the size of MinHeap and the
      element 
      a. is greater than the top element of MinHeap then pop the top
         element from MinHeap and insert into the MaxHeap and insert the
         new element to MinHeap else {insert the new element to the MaxHeap. 
      
    Calculate the new median as the average of top of elements
    of both max and MinHeap.
    
    ● If the size of both heaps is the same, insert the element into the
      MaxHeap.

*/

priority_queue<int, vi, greater<int>> pqmin;
priority_queue<int, vi> pqmax;

// MVP
void insert(int x){
    if(pqmin.size() == pqmax.size()){
        // Base or Corner Case
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }
        
        if(x < pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    }
    else{
        // 2 cases
        // Case 1: size of maxHeap > size of minHeap
        // case 2: size of maxHeap < size of minHeap
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top())
                pqmin.push(x);

            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x <= pqmin.top())
                pqmax.push(x);
            
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
    return;
}

double findMedian(){
    
    if(pqmin.size() == pqmax.size())
        return ((pqmin.top() + pqmax.top())/2.0);
    
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    
    else
        return pqmin.top();
}

int main(){
    
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    
    return 0;
}