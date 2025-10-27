#include <bits/stdc++.h>
using namespace std;

// 最大宽度坡
// 给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]
// 这样的坡的宽度为 j - i，找出 A 中的坡的最大宽度，如果不存在，返回 0
// 测试链接 : https://leetcode.cn/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), r = 1;
        vector<int> stk(n);
        // 默认0下标在栈里,遍历数组
        // 如果栈顶大于nums[i],i下标入栈
        for(int i = 1; i < n; i++){
            if(nums[stk[r - 1]] > nums[i]){
                stk[r++] = i;
            }
        }
        int ans = 0;
        // 从右向左遍历数组,计算最大宽度
        for(int i = n - 1; i >= 0; i--){
            while(r > 0 && nums[i] >= nums[stk[r - 1]]){
                ans = max(ans, i - stk[--r]);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}
