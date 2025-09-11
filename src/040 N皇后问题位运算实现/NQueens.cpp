#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;


// N皇后问题
// 测试链接 : https://leetcode.cn/problems/n-queens-ii/

class Solution1 {
public:
    int totalNQueens(int n) {
        if(n < 1){
            return 0;
        }
        vector<int> path(n);
        return f(0, path, n);
    }
    int f(int i, vector<int>& path, int n){
        if(i == n){
            return 1;
        }
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(check(path, i, j)){
                //表示(i, path[j])放了皇后
                path[i] = j;
                ans += f(i + 1, path, n);
            }
        }
        return ans;
    }
    bool check(vector<int>& path, int i, int j){
        for(int k = 0; k < i; k++){
            //之前放过的列不能放,之前放过的对角线不能放
            //对角线判定: 当前行 - 之前行 == 当前列 - 之前列
            if(j == path[k] || abs(i - k) == abs(j - path[k])){
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    int totalNQueens(int n) {
        if(n < 1){
            return 0;
        }
        int limit = (1 << n) - 1;
        return f(limit, 0, 0, 0);
    }
    // limit : 当前是几皇后问题
	// 之前皇后的列影响：col
	// 之前皇后的右上 -> 左下对角线影响：left
	// 之前皇后的左上 -> 右下对角线影响：right
    int f(int limit, int col, int left, int right){
        if(col == limit){
            return 1;
        }
        // 总限制
        int ban = col | left | right;
        // ~ban : 1可以放皇后,0不可以放
        int candidate = limit & (~ban);
        // 防止皇后的尝试
        int place = 0;
        //一共有多少有效方法
        int ans = 0;
        while(candidate != 0){
            place = candidate & (-candidate);
            candidate ^= place;
            ans += f(limit, col | place, (left | place) >> 1, (right | place) << 1);
        }
        return ans;
    }
};

int main(){
    int n = 14;
    time_point<system_clock> start, end;
    Solution1 solution1;
    Solution2 solution2;
    cout << "测试开始" << endl;
    cout << "解决" << n << "皇后问题" << endl;
    // 测试方法1
    start = system_clock::now();
    cout << "方法1答案 : " << solution1.totalNQueens(n) << endl;
    end = system_clock::now();
    cout << "方法1运行时间 : " << duration_cast<milliseconds>(end - start).count() << " 毫秒" << endl;
    // 测试方法2
    start = system_clock::now();
    cout << "方法2答案 : " << solution2.totalNQueens(n) << endl;
    end = system_clock::now();
    cout << "方法2运行时间 : " << duration_cast<milliseconds>(end - start).count() << " 毫秒" << endl;
    cout << "测试结束" << endl;
    cout << "=======" << endl;
    cout << "只有位运算的版本,才能10秒内跑完16皇后问题的求解过程" << endl;
    // 单独测试16皇后
    start = system_clock::now();
    int ans = solution2.totalNQueens(16);
    end = system_clock::now();
    cout << "16皇后问题的答案 : " << ans << endl;
    cout << "运行时间 : " << duration_cast<milliseconds>(end - start).count() << " 毫秒" << endl;
    return 0;
}
