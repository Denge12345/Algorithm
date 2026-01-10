#include <bits/stdc++.h>
using namespace std;

// 满足不等式的最大值
// 给你一个数组 points 和一个整数 k
// 数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序
// 也就是说 points[i] = [xi, yi]
// 并且在 1 <= i < j <= points.length 的前提下，xi < xj 总成立
// 请你找出 yi + yj + |xi - xj| 的 最大值，
// 其中 |xi - xj| <= k 且 1 <= i < j <= points.length
// 题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
// 测试链接 : https://leetcode.cn/problems/max-value-of-equation/

class Solution {
public:
    // 已知所有的点都是根据x值排序的！
	// 任何两个点，组成指标，要求 : 后x - 前x <= k
	// 返回最大指标
    vector<vector<int>> q = vector<vector<int>>(100009, vector<int>(2));
    int h, t;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        h = t = 0;
        int n = points.size();
        int ans = INT_MIN;
        for(int i = 0, x, y; i < n; i++){
            // i 号点为此时的点，当前的后面点，看那个点的 y - x 值最大，x 距离又不能超过 k
            x = points[i][0];
            y = points[i][1];
            while(h < t && q[h][0] + k < x){
                // 单调队列头部的可能性过期了，头部点的 x 与当前点 x 距离超过了 k
                h++;
            }
            if(h < t){
                ans = max(ans, x + y + q[h][1] - q[h][0]);
            }
            // i 号点的 x 和 y，从尾部进入单调队列
            // 根据 y - x 从 大 -> 小
            while(h < t && q[t - 1][1] - q[t - 1][0] <= y - x){
                t--;
            }
            q[t][0] = x;
            q[t++][1] = y;
        }
        return ans;
    }
};

int main(){

    return 0;
}
