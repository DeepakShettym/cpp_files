#include<iostream>
using namespace std;


int main(){
  int num = 10;

  int ans = num & (num - 1);

  cout << ans << endl;

  return 0;
}