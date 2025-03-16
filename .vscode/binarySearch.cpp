#include <iostream>
#include <vector>

using namespace std;

int binarySearchLeft(vector<int>& arr, int size, int key) {
    int ans = -1;
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } 
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int binarySearchRight(vector<int>& arr, int size, int key) {
    int ans = -1;
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        } 
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    int ans1 = binarySearchLeft(nums, size, target);
    int ans2 = binarySearchRight(nums, size, target);

    return {ans1, ans2};
}
int countFreq(vector<int>& arr, int target) {
    int size = arr.size();  // Corrected from `.length()`
    int ans1 = binarySearchLeft(arr, size, target);
    int ans2 = binarySearchRight(arr, size, target);
    
    if(ans1 == -1 && ans2 == -1 ){
        return 0;
    }
    
    return (ans2 - ans1) + 1;
    
    
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);
    cout << "First occurrence: " << result[0] << "\n";
    cout << "Last occurrence: " << result[1] << "\n";

    return 0;
}
