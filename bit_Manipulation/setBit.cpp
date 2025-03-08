#include<iostream>
using namespace std;

int setBit(int num,int i){
  num =  num | (1 << i);
  return num;
}

int main(){

  int num = 9;

  int ans = setBit(num , 2);

  cout << ans << endl;
  


  return 0;
}

// output is 13