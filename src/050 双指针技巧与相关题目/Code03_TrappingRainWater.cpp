#include <bits/stdc++.h>
using namespace std;

// 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water/

// 辅助数组的解法（不是最优解）
// 时间复杂度O(n)，额外空间复杂度O(n)
// 提交时将类名改为Solution
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // lmax表示从0..i的最大值
        vector<int> lmax(n, 0), rmax(n, 0);
        lmax[0] = nums[0];
        for(int i = 1; i < n; i++){
            lmax[i] = max(height[i], lmax[i - 1]);
        }
        // rmax表示从i..n-1的最大值
        rmax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rmax[i] = max(height[i], rmax[i + 1]);
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans += max(min(lmax[i], rmax[i]) - height[i], 0);
        }
        return ans;
    }
};

// 双指针的解法（最优解）
// 时间复杂度O(n)，额外空间复杂度O(1)
// 提交时将类名改为Solution
class Solution2 {
public:
    int trap(vector<int>& height) {
        int l = 1, r = height.size() - 2, lmax = height[0], rmax = height[height.size() - 1];
        int ans = 0;
        while(l <= r){
            if(lmax <= rmax){
                ans += max(lmax - height[l], 0);
                lmax = max(lmax, height[l++]);
            }else{
                ans += max(rmax - height[r], 0);
                rmax = max(rmax, height[r--]);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}
