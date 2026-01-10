#include <bits/stdc++.h>
using namespace std;

// 和至少为K的最短子数组
// 给定一个数组arr，其中的值有可能正、负、0
// 给定一个正数k
// 返回累加和>=k的所有子数组中，最短的子数组长度
// 测试链接 : https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    // sum[i] 表示前i个数的前缀和
    vector<int> sum = vector<long long>(100009);
    vector<int> q = vector<int>(100009);
    int h, t;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        h = t = 0;
        for(int i = 0; i < n; i++){
            sum[i + 1] = sum[i] + nums[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i <= n; i++){
            while(h < t && sum[i] - sum[q[h]] >= k){
                // 当前的前缀和 - 头前缀和
                ans = min(ans, i - q[h++]);
            }
            // 小 -> 大
            while(h < t && sum[q[t - 1]] >= sum[i]){
                t--;
            }
            q[t++] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){

    return 0;
}
