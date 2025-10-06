#include <bits/stdc++.h>
using namespace std;

// 用邮票贴满网格图
// 给你一个 m * n 的二进制矩阵 grid
// 每个格子要么为 0 （空）要么为 1 （被占据）
// 给你邮票的尺寸为 stampHeight * stampWidth
// 我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：
// 覆盖所有空格子，不覆盖任何被占据的格子
// 可以放入任意数目的邮票，邮票可以相互有重叠部分
// 邮票不允许旋转，邮票必须完全在矩阵内
// 如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false
// 测试链接 : https://leetcode.cn/problems/stamping-the-grid/

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum[i + 1][j + 1] = grid[i][j];
            }
        }
        build(sum);
        vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));
        for(int a = 1, c = a + stampHeight - 1; c <= n; a++, c++){
            for(int b = 1, d = b + stampWidth - 1; d <= m; b++, d++){
                if(sumRegion(sum, a, b, c, d) == 0){
                    add(diff, a, b, c, d);
                }
            }
        }
        build(diff);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && diff[i + 1][j + 1] == 0){
                    return false;
                }
            }
        }
        return true;
    }
    void build(vector<vector<int>>& m){
        for(int i = 1; i < m.size(); i++){
            for(int j = 1; j < m[0].size(); j++){
                m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
            }
        }
    }
    int sumRegion(vector<vector<int>>& sum, int a, int b, int c, int d){
        return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
    }
    void add(vector<vector<int>>& diff, int a, int b, int c, int d){
        diff[a][b] += 1;
        diff[c + 1][b] -= 1;
        diff[a][d + 1] -= 1;
        diff[c + 1][d + 1] += 1;
    }
};

int main(){

    return 0;
}
