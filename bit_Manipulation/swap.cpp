#include<iostream>
using namespace std;

int main(){


  int a = 10;

  int b = 20;

  a = a ^ b; 

  b = a ^ b;  // a ^ b ^ b  : b ^ b = 0 so b is a

  a = a ^ b;  // a ^ b ^ a  : a ^ a = 0 so a is b

  cout << "a : " << a << endl;

  cout <<  "b : " << b << endl;

  return 0;
}

//output  a = 20 , b = 10;