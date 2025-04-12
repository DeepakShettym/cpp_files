#include<vector>

class Solution {
  public:
        int findMin(vector<int>& nums) {
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
  
     int search(vector<int>& nums, int target) {
      int pivot = findMin(nums);
      int end = nums.size() - 1;
  
      if (target >= nums[pivot] && target <= nums[end]) {
          return binarySearch(nums, pivot, end, target);
      } else {
          return binarySearch(nums, 0, pivot - 1, target);
      }
  }
  
  
  };