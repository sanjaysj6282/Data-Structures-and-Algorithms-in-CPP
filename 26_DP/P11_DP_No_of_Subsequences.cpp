#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
using namespace std;

#define vi vector<int> 
#define pi pair<int, int>
#define ff first
#define ss second
#define vii vector<pi>
#define vvi vector<vi> 
#define rep(i,a,b) for(int i=a; i<b; i++)

#define ll long long

const int M=1e4+3, MOD=1e9+7;

// Hard (Looks easy but)
/*
Problem
You are given a string s consisting of lowercase letters latin letters (‘a’ to ‘z’) and
some ‘?’. Your task is to find the number of subsequences ‘abc’ in all the strings.
‘?’ should be replaced by either of {‘a’, ‘b’, ‘c’}.

eg :- ac?b?c

Possible Strings  |  No of Subsequences ‘abc’
    acabac        |          2
    acabbc        |          4
    acabcc        |          4
    acbbac        |          2
    acbbbc        |          3
    acbbcc        |          4
    accbac        |          1
    accbbc        |          2
    accbcc        |          2
_________________________________
    Total                   24

Brute force approach
1. Compute all the strings and then count subsequences (“abc”) in each string.
                Time complexity: O(2^n)
where n is the length of string.


Optimal Approach (Using dynamic programming)
Declare 4 variables,
A. e   - denoting count of all possible strings upto current element.
B. a   - denoting count of subsequences (‘a’) in all the strings upto 
         current elements.
C. ab  - denoting count of subsequences (‘ab’) in all the strings upto 
         current element.
D. abc - denoting count of subsequences (‘abc’) in all the strings upto 
         current element.

According to this table, update the above variables while iterating in the string.

Curr_Element    e        a           ab         abc
“a”            (e)      (a)+e       (ab)       (abc)
“b”            (e)      (a)       (ab)+(a)     (abc)
“c”            (e)      (a)         (ab)       (abc) + (ab)
“d-z”          (e)      (a)         (ab)       (abc)
“?”           3*(e)   3*(a)+e    3*(ab)+(a)    3*(abc)+(ab)

Dry Run
eg "ac?b?c"

Variables  Curr ‘a’  ‘c’  ‘?’  ‘b’  ‘?’  ‘c’
e           1    1    1    3    3    9    9
a           0    1    1    4    4    15   15
ab          0    0    0    1    5    19   19
abc         0    0    0    0    0    5    24

*/
int Subsequences(string s, int n){
    int e=1;
    int a=0;
    int ab=0;
    int abc=0;

    rep(i, 0, n){
        if(s[i]=='a')
            a += e;
        else if(s[i]=='b')
            ab +=a;
        else if(s[i]=='c')
            abc += ab;
        else if(s[i]=='?'){
            // VIMP
            abc = 3*abc + ab;
            ab  = 3*ab + a;
            a   = 3*a +e;
        }
    }
    return abc;
}

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << Subsequences(s, n) << endl;

    return 0;
}