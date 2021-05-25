#include <iostream>
using namespace std;

/*
Divide And Conquer
Count Inversions
Count the inversions in the given array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Sample Test Case:
A: [3, 5, 6, 9, 1, 2, 7, 8]
Inversions: 10
Explanation: (3,1), (3,2), (5,1), (5,2), (6,1), (6,2), (9,1), (9,2), (9,7), (9,8)


Brute Force:
int inv = 0;
for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
        if(a[i] > a[j])
            inv++;
    }
}
cout<<inv;
Time Complexity: O(N2)


Using Divide and Conquer:
Idea: Divide the array into two parts, get the inversions for the left part and get
the inversions for the right part recursively and merge the two arrays, and get
their inversions.

O(NlogN)
*/

long long Merge(int arr[],int l,int mid,int r){

    long long inv = 0;

    int n1 = mid-l+1;
    int n2 = r-mid;
    // temp arrays
    int a[n1];
    int b[n2];  

    for(int i = 0; i < n1;i++)
        a[i]=arr[l+i];

    for(int i = 0; i < n2;i++)
        b[i]=arr[mid+1+i];

    // Pointers
    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];

            // MOST IMP
            // VIMP
            inv += n1-i;
            // a[i],a[i+1],..(every remaing element is greater than b) > b[j] i < j

            k++;
            j++;
        }
    }

    // VIMP
    // Corner case
    while(i < n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = b[j];
        k++;
        j++;
    }

    return inv;
}

long long  MergeSort(int arr[],int l,int r){
    long long inv = 0;
    if(l < r){
        int mid = (l+r)/2;
        inv += MergeSort(arr,l,mid);
        inv += MergeSort(arr,mid+1,r);

        inv += Merge(arr,l,mid,r);
    }
    return inv;
}
int main(){

    // int arr[] = {5,4,3,2,1};

    // cout << MergeSort(arr,0,4);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i];

    cout << MergeSort(arr,0,n-1);
    
    return 0;
}
