#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void biggest(){
    string s = "123467897";
    sort(s.begin(),s.end(),greater<int>{});

    cout << s[0] << "\n";

}

int main(){
    biggest();

    return 0;
}
