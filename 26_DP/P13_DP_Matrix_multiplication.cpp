#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
#include <set>
#include <unordered_set>
#include <cstring>
#include <climits>
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a;i<b;i++)

#define ll long long

const int M=1e4+3, MOD=1e9+7;

// VIMP
// Hard in DP

/*

Problem
We are given n matrices, we have to multiply them in such a way 
that total number of operations are minimum.

Example
        []1x2   []2x3   []3x4
           A       B       C
Since we know multiplication of matrices is associative, hence
A(BC) = (AB)C


Example
    The Dimension of ith matrix is a[i-1] x a[i].
Example
        {10, 20, 30, 20, 30}
    M1-> a[0] x a[1] = 10 x 20
    M2-> a[1] x a[2] = 20 x 30
    M3-> a[2] x a[3] = 30 x 20
    M4-> a[3] x a[4] = 20 x 30
Therefore dimension of matrix multiplication from
    Mi to Mj-> a[i-1] x a[j]
Example: M1 M2 M3-> a[0] x a[3] = 10 x 20

Our Recurrence Relation becomes
f(M1.M2....Mn) = min(f(M1....Mk) + f(Mk+1....Mn) + a[0] x a[k] x a[N])
where 1<= k <= N-1 (cut at k)

    4 matrices A, B, C, D.
We can see that answer of ABCD depends on
1. (A)(BCD)
2. (AB)(CD)
3. (ABC)(D)
Whichever from 1. , 2. or 3. gives minimum operations, that is the answer.
In other words, we can say that 3 cuts are possible,
(i)       A | B C D
(ii)    A B | C D
(iii) A B C | D



Approach 1
1. Write the recursive solution.
2. Memoize it.

Approach 2 (Tabulation (Bottom Up))
1. Build from base.
2. For each gap=0 to gap=n-2, compute all submatrix multiplication 
   and their results.
3. Build the answer using,
            for every k=i to k=j-1
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] x a[k] x a[j])

            Time complexity: O(n^3)

*/


int a[M];

// Memoization
int dp[M][M];
int mcm(int i, int j){
    if(i==j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j]=MOD;
    for(int k=1; k<j; k++)
        dp[i][j] = min(dp[i][j], 
                       mcm(i,k) + mcm(k+1,j) + a[i-1]*a[k]*a[j]);

    return dp[i][j];
}

// Tabulation
int mcm_t(int n){
    /* For simplicity, one extra row and one extra column are
    allocated in m[][]. 0th row and 0th column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++){
        for (i = 1; i < n - L + 1; i++){
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++){
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + a[i - 1] * a[k] * a[j];
                
                m[i][j] = min(m[i][j], q);
            }
        }
    }
 
    return m[1][n - 1];
}

int main(){
    int n;
    cin >> n;
    rep(i, 0, n)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    cout << mcm(1, n-1) << endl;

    cout << mcm_t(n);

    return 0;
}