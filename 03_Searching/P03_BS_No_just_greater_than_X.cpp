#include <iostream>
// Optimisation over search
using namespace std;

// No just ">=X"
int bs(){
    int x; cin >> x;
    int arr[]={2, 3, 5, 6, 8, 10, 12};
    int l=0;
    int r=sizeof(arr)/sizeof(arr[0]);
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        // Also for if and else if
        // if(arr[mid]>=x){
        //    ans=arr[mid];
        //    r=mid-1;
        // }  
        if(arr[mid]==x)
            return mid;
    
        // Better answer can be at more towards left
        else if(arr[mid]>x){
            ans=arr[mid];
            r=mid-1;
        }
        
        else
            l=mid+1;
    }
    return ans;
}

int main()
{
    cout << bs();
    

    return 0;
}
