// Refer Bit operaters first 
// IMP --> Interview
// Refer both video for clear explanation
#include <iostream>
using namespace std;

// Tricky but easy
// It's better to use left shift operator

// Right/left shift operators shift bits by pos
// i.e, If it's Pos=1 then we shift all digits by 1

// To get bit at a required index pos
// Indexing : n-1,n-2,...,2,1,0   unlike (0,1,2,3....n-1)
int Get_bit(int n,int pos){
    // Paranthesis VIMP  -> Due to precedence of operators
    return((n & (1<<pos))!=0);
    // Or
    // return ((n >> pos) & 1);
}

// Put 1 At pos 
int Set_bit(int n,int pos){
    return(n | (1<<pos));
}

// Put 0 At pos 
int Clear_bit(int n,int pos){
    int mask = ~(1<<pos);
    return(n & mask);
}

// Update   pos = value
int Update_bit(int n,int pos,int value){
    // 1st clear bit and then modified set bit
    int mask = ~(1<<pos);
    n = n & mask;
    return(n | (value<<pos));
}

int main(){

    // We get the real not it's binary form
    cout << Get_bit(5,2) << "\n";

    cout << Set_bit(5,1) << "\n";

    cout << Clear_bit(5,2) << "\n";

    cout << Update_bit(5,2,1) << "\n";

    return 0;
}