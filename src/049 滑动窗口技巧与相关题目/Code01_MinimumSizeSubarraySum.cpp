#include <bits/stdc++.h>
using namespace std;

// 累加和大于等于target的最短子数组长度
// 给定一个含有 n 个正整数的数组和一个正整数 target
// 找到累加和 >= target 的长度最小的子数组并返回其长度
// 如果不存在符合条件的子数组返回0
// 测试链接 : https://leetcode.cn/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        for(int l = 0, r = 0, sum = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum - nums[l] >= target){
                sum -= nums[l++];
            }
            if(sum >= target){
                ans = min(ans, r - l + 1);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main(){

    return 0;
}
