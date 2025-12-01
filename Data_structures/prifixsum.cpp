#include<iostream>
#include<vector>
#include<map>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    long long sum = 0;

    int len = 0;

    map<long long ,int> mp;


    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];


        if(sum == k){
            len = max(len , i + 1);
        }

        long long rem = sum - k;

        if(mp.find(rem) != mp.end()){
            len = max(len , i - mp[rem]);
        }

        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    return len;


}