#include <bits/stdc++.h>
using namespace std;

// 最强祝福力场
// 小扣在探索丛林的过程中，无意间发现了传说中"落寞的黄金之都"
// 而在这片建筑废墟的地带中，小扣使用探测仪监测到了存在某种带有「祝福」效果的力场
// 经过不断的勘测记录，小扣将所有力场的分布都记录了下来
// forceField[i] = [x,y,side] 
// 表示第 i 片力场将覆盖以坐标 (x,y) 为中心，边长为 side 的正方形区域。
// 若任意一点的 力场强度 等于覆盖该点的力场数量
// 请求出在这片地带中 力场强度 最强处的 力场强度
// 注意：力场范围的边缘同样被力场覆盖。
// 测试链接 : https://leetcode.cn/problems/xepqZ5/

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        int n = forceField.size();
        vector<long long> xs(n << 1, 0);
        vector<long long> ys(n << 1, 0);
        for(int i = 0, k = 0, p = 0; i < n; i++){
            long long x = forceField[i][0];
            long long y = forceField[i][1];
            long long r = forceField[i][2];
            xs[k++] = (x << 1) - r;
            xs[k++] = (x << 1) + r;
            ys[p++] = (y << 1) - r;
            ys[p++] = (y << 1) + r;
        }
        int sizex = getSize(xs);
        int sizey = getSize(ys);
        vector<vector<int>> diff(sizex + 2, vector<int>(sizey + 2, 0));
        for(int i = 0, a, b, c, d; i < n; i++){
            long long x = forceField[i][0];
            long long y = forceField[i][1];
            long long r = forceField[i][2];
            a = rank(xs, (x << 1) - r, sizex);
            b = rank(ys, (y << 1) - r, sizey);
            c = rank(xs, (x << 1) + r, sizex);
            d = rank(ys, (y << 1) + r, sizey);
            add(diff, a, b, c, d);
        }
        int ans = 0;
        for(int i = 1; i < diff.size(); i++){
            for(int j = 1; j < diff[0].size(); j++){
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                ans = max(ans, diff[i][j]);
            }
        }
        return ans;
    }
    int getSize(vector<long long>& nums){
        sort(nums.begin(), nums.end());
        int size = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[size - 1]){
                nums[size++] = nums[i];
            }
        }
        return size;
    }
    int rank(vector<long long>& nums, long long v, int size){
        int l = 0;
        int r = size - 1;
        int m, ans = 0;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] >= v){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans + 1;
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
