#include <bits/stdc++.h>
using namespace std;

// 边框为1的最大正方形
// 给你一个由若干 0 和 1 组成的二维网格 grid
// 请你找出边界全部由 1 组成的最大 正方形 子网格
// 并返回该子网格中的元素数量。如果不存在，则返回 0。
// 测试链接 : https://leetcode.cn/problems/largest-1-bordered-square/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        build(n, m, grid);
        int ans = 1;
        if(sum(0, 0, n - 1, m - 1, grid) == 0){
            return 0;
        }
        for(int a = 0; a < n; a++){
            for(int b = 0; b < m; b++){
                for(int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m; c++, d++, k++){
                    if(sum(a, b, c, d, grid) - sum(a + 1, b + 1, c - 1, d - 1, grid) == (k - 1) << 2){
                        ans = k;
                    }
                }
            }
        }
        return ans * ans;
    }
    void build(int n, int m, vector<vector<int>>& grid){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] += get(i - 1, j, grid) + get(i, j - 1, grid) - get(i - 1, j - 1, grid);
            }
        }
    }
    int sum(int a, int b, int c, int d, vector<vector<int>>& grid){
        return a > c ? 0 : get(c, d, grid) - get(c, b - 1, grid) - get(a - 1, d, grid) + get(a - 1, b - 1, grid);
    }
    int get(int i, int j, vector<vector<int>>& grid){
        return (i < 0 || j < 0) ? 0 : grid[i][j];
    }
};

int main(){

    return 0;
}
