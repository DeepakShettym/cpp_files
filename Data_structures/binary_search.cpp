#include<vector>
#include<iostream>
using namespace std;

class Solution {
  public:
        int findMinPivot(vector<int>& nums) {
          int start = 0;
          int end = nums.size() - 1;
  
           int mid = start + (end - start) / 2;
  
          while (start < end) {
  
              if (nums[mid] > nums[end]) {
                  start = mid + 1;
              } else {
                  end = mid;
              }
  
              mid = start + (end - start) / 2;
          }
  
          return mid; 
      }
  
      int binarySearch(vector<int>& arr,int start ,int end ,int key) {
  
      int mid = start + (end-start)/2;
  
      while(start <= end) {
  
          if(arr[mid] == key) {
              return mid;
          }
  
        
          if(key > arr[mid]) {
              start = mid + 1;
          }
          else{ 
              end = mid - 1;
          }
  
          mid = start + (end-start)/2;
      }
      
      return -1;
  }
  
     int searchInRotatedArray(vector<int>& nums, int target) {
      int pivot = findMinPivot(nums);
      int end = nums.size() - 1;
  
      if (target >= nums[pivot] && target <= nums[end]) {
          return binarySearch(nums, pivot, end, target);
      } else {
          return binarySearch(nums, 0, pivot - 1, target);
      }
  }

  int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int start = 0;
    int end = x;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

       
        if (mid == x / mid) {
            return mid;
        }

        if (mid < x / mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

  
  };