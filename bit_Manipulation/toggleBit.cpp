#include<iostream>
using namespace std;

int toggleBit(int num,int i){
  num =  num ^ (1 << i);
  return num;
}

int main(){

  int num = 15;

  int ans = toggleBit(num , 3);

  cout << ans << endl;
  


  return 0;
}

// output is 13