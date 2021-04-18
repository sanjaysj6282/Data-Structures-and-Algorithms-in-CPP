#include<iostream>
using namespace std;

int main()
{
  int savings;
  cin>>savings;

  if(savings<500)
  {
    cout<<"I am here with Jaddu";
  }

  else if(savings>500 &&  savings<1000)
  {
    cout<<"I am here with Namma";
  }

  else
  {
    cout<<"I am here with Akash";
  }
  
  return 0;

}