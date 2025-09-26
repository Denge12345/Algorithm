#include <bits/stdc++.h>
using namespace std;

// 使数组和能被P整除
// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空）
// 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
// 子数组 定义为原数组中连续的一组元素。
// 测试链接 : https://leetcode.cn/problems/make-sum-divisible-by-p/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int mod = 0;
        for(int num : nums){
            mod = (mod + num) % p;
        }
        if(mod == 0){
            return 0;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = INT_MAX;
        for(int i = 0, cur = 0, find; i < nums.size(); i++){
            cur = (cur + nums[i]) % p;
            find = cur >= mod ? (cur - mod) : (cur + p - mod);
            // find = (cur + p - mod) % p;
            if(mp.count(find)){
                ans = min(ans, i - mp[find]);
            }
            mp[cur] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};

int main(){

    return 0;
}