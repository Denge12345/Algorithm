#include <bits/stdc++.h>
using namespace std;

// 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度
// 每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积
// 测试链接：https://leetcode.cn/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), r = 0;
        vector<int> stk(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(r > 0 && heights[stk[r - 1]] >= heights[i]){
                int cur = stk[--r];
                int left = r > 0 ? stk[r - 1] : -1;
                ans = max(ans, (i - left - 1) * heights[cur]);
            }
            stk[r++] = i;
        }
        while(r > 0){
            int cur = stk[--r];
            int left = r > 0 ? stk[r - 1] : -1;
            ans = max(ans, (n - left - 1) * heights[cur]);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
