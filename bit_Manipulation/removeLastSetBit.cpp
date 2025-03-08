#include<iostream>
using namespace std;

int removeLastSetBit(int num){
  int i = 0;

  while( ( num & (1 << i) ) == 0){
    i++;
  }
  
  int res = num ^ (1 << i);

  return res;
}
int main(){
  int ans = removeLastSetBit(12);

  cout << ans << endl;

  return 0;
}