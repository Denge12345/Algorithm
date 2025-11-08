#include <bits/stdc++.h>
using namespace std;

// 滑动窗口最大值（单调队列经典用法模版）
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 测试链接 : https://leetcode.cn/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), h = 0, t = 0;
        vector<int> maxDeque(n);
        // 先让0..k-1进入单调队列
        for(int i = 0; i < k - 1; i++){
            // 大 -> 小
            while(h < t && nums[maxDeque[t - 1]] <= nums[i]){
                t--;
            }
            maxDeque[t++] = i;
        }
        int m = n - k + 1;
        vector<int> ans(m);
        for(int l = 0, r = k - 1; l < m; l++, r++){
            // 右边界扩大
            while(h < t && nums[maxDeque[t - 1]] <= nums[r]){
                t--;
            }
            maxDeque[t++] = r;
            // 记录答案
            ans[l] = nums[maxDeque[h]];
            // 左边界缩小
            if(maxDeque[h] == l){
                h++;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}
