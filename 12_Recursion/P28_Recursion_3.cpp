// Clue
// For almost all recursive string problems
// "substr(1)"is used
#include <iostream>
using namespace std;

// IMP
void reverse(string s){
    if(s.length() == 0){ // Base case
        return;
    }

    // Similar to "Print in increasing order"
    string ros = s.substr(1); // Substring after the first element in the string 
    reverse(ros);
    cout << s[0]; // O th element is VIMP

}

void replacePi(string s){
    if(s.length() == 0){
        return;
    }
    if(s[0] == 'p' && s[1] == 'i'){
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else{
        cout << s[0];
        replacePi(s.substr(1));
    }
}

// Tricky
// VIMP
void Tower_of_Hanoi(int n,char src,char dest,char helper){

    if(n == 0){
        return; // Base case
    }

    Tower_of_Hanoi(n-1,src,helper,dest);
    cout << "Move from " << src << " to" << dest << endl;
    Tower_of_Hanoi(n-1,helper,dest,src);

}

// Most IMP --> from these
// Look for execution pattern
// Both move all x and removedup are similar
string removeDup(string s){
    if(s.length() == 0){
        return "";
    }
    // Study the execution very carefully
    char ch = s[0];
    cout << s <<"  "<< ch << endl;

    // if(ch != NULL)
    // cout << ch << "\n";
    string ans = removeDup(s.substr(1));

    // To check the execution
    cout << "ans= " << ans << " " <<"char= " << ch << "\n";

    if(ch == ans[0]){
        return ans;
    }
    return (ch + ans);
}

// Hard
// See video
string moveallx(string s){
    if(s.length() == 0){
        return "";
    }

    char ch= s[0];
    string ans = moveallx(s.substr(1));

    // The only difference between the both
    if(ch == 'x'){
        return ans + ch;
    }
    return ch +ans;
}

int main(){

    string s = "Binod";
    reverse(s);

    replacePi("pipojihhpxxxpippppiphdpij");
    cout << "\n";

    Tower_of_Hanoi(3,'A','C','B');
    cout << "\n";

    cout << removeDup("aaaddddeettllluuu") << endl;

    cout << removeDup("Saaam") << endl;

    cout << moveallx("axxxxcxcbxerhsidznxzmxx") << endl;

    return 0;
}