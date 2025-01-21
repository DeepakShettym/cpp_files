#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool customComparatorDesnd(int a, int b){
  return a > b;
}
bool customComparatorasnd(int a, int b){
  return a < b;
}
int main(){
  vector<int> vector = {1,22,99,56,71,44};
  sort(vector.begin(),vector.end(),customComparatorDesnd);

  for(int num:vector){
    cout << num  << " ";
  }

  cout << endl;

  sort(vector.begin(),vector.end(),customComparatorasnd);

  for(int num:vector){
     cout << num  << " ";
  } 
  return 0;
}