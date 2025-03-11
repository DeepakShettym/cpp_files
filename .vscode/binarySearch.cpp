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

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);
    cout << "First occurrence: " << result[0] << "\n";
    cout << "Last occurrence: " << result[1] << "\n";

    return 0;
}
