#include <iostream>
#include <limits.h>
using namespace std;

// Easiest
// Amazon, Samsung, Snapdeal, Accolite
// Similar to First_Repeating_Element()
/*
Arrays Challenge - Smallest Positive Missing Number
(Amazon, Samsung, Snapdeal, Accolite)
Problem
Find the smallest positive missing number in the given array.
Example: [0, -10, 1, 3, -20], Ans = 2
Intuition
If in O(1), we can tell if an element is present in an array, then our task will be
simpler.
For that, we will maintain a Check[ ] array, that will if an element x is present in
the array or not.
It will be of boolean type as we only need to check the presence or absence of the
number.
Steps to Solve:
1. Build the Check[ ] array initialized with False at all indices.
2. By iterating over the array and marking non-negative a[i] as true i.e.
if(a[i] >= 0)
 check[a[i]] = True
3. Iterate in the Check[ ] from i=1, BREAK the loop when you find check[i] =
False and store that i in the ans variable.
4. Output the ans.
*/
void Smallest_Positive_Missing_Number(){
    int n,s;
    cin >> n >> s;

    int a[n];

    for (int i = 0;i < n;i++)
        cin >> a[i];
    
    //  const int N = 1e6 + 2;
    //  1e6... not working
    const int N =10000;

    bool check[n];
    for (int i = 0;i < N;i++)
        cin >> check[i];

    for(int i = 0; i < n; i++){
        if(a[i] >= 0)
            check[a[i]] = true;
    }

    int ans = -1;

    for(int i = 1; i < N;i++){
        if(check[i] == false){
            ans = i;
            break;
        }
    }
    cout << ans << endl;

}

int main(){
    Smallest_Positive_Missing_Number();  
    cout << endl;

    return 0;
}