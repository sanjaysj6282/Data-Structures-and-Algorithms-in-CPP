/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) 
required to convert ‘str1’ into ‘str2’.  

1. Insert
2. Remove
3. Replace
All of the above operations are of equal cost. 

*/
/*

Algorithm
The idea is process all characters one by one staring from either from left or right sides of both strings. 
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.  

m: Length of str1 (first string)
n: Length of str2 (second string)

If last characters of two strings are same,
   nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), 
   we consider all operations on ‘str1’, consider all three operations on last character of first string,
   recursively compute minimum cost for all three operations and take minimum of three values. 

1. Insert: Recur for m and n-1
2. Remove: Recur for m-1 and n
3. Replace: Recur for m-1 and n-1

*/

#include <iostream>
using namespace std;
 
// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];
 
    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
 
    return dp[m][n];
}
 
int main(){

    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistDP(str1, str2, str1.length(),
                       str2.length());
 
    return 0;
}