#include <bits/stdc++.h>
using namespace std;

// 最大矩形
// 给定一个仅包含 0 和 1 、大小为 rows * cols 的二维二进制矩阵
// 找出只包含 1 的最大矩形，并返回其面积
// 测试链接：https://leetcode.cn/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
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
