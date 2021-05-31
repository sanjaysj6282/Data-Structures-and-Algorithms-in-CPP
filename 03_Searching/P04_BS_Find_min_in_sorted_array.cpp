// Find Minimum in Rotated Sorted Array, https://leetcode.com/explore/learn/card/binary-search/126/template-ii/949/

// Here the property is a[mid] <= a[n-1] (last)
// VIMP
// Dont use a[mid]>=arr[0] (first)
// Since for sorted array it results in 
// T  T  T  T  T   
//{1, 2, 3, 4, 5}
// So we cant find 1st false

// Whereas for last
// F  F  F  F  F  
//{1, 2, 3, 4, 5}
class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int left = 0, right = n - 1;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(a[mid] <= a[n-1]) {
                ans = a[mid];
                right = mid - 1; // look for something even smaller on the left
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};