#include <bits/stdc++.h>
using namespace std;

// 返回无序数组中累加和为给定值的子数组个数
// 测试链接 : https://leetcode.cn/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        mp[0] = 1;
        for(int i = 0, sum = 0; i < nums.size(); i++){
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};

int main(){

    return 0;
}
