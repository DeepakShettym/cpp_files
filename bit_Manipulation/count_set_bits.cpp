#include<iostream>
using namespace std;

int main(){
  int count =  0;
  
  int n = 25;

  while(n!=0){
    n = n & (n-1);
    count ++;
  }

  cout << count << endl;

  
  return 0;
}