#include<iostream>
using namespace std;


int main(){

  int num = 2;
  
  string res = "";
  while(num > 0){
    if(num % 2==1){
      res +="1";
    }else{
      res +="0";
    }
  
    num /= 2;
  }

  for(int i=res.length()-1;i >=0;i--){
    cout << res[i];
  }

  return 0;
}