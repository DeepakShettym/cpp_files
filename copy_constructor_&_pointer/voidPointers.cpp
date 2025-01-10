
#include<iostream>
#include <unordered_map>
using namespace std;


unordered_map<int, int> frequency(unordered_map<int, int> map, int arr[5]){
     for(int i=0 ;i<arr[5];i++){
        int elem  = arr[i];

           if(map.find(elem)!= NULL){
             map[elem] = map[elem] + 1;
        }else{
            myMap.emplace(elem, 1);
        }
     }
     return map;
}


int main()
{
  unordered_map<int, int> map;

  int arr = {1,2,3,4,5};

  frequency(map, int arr[5]);
}

