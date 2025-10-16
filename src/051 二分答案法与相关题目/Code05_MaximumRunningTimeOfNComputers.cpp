#include <bits/stdc++.h>
using namespace std;

// 同时运行N台电脑的最长时间
// 你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries
// 其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟
// 你想使用这些电池让 全部 n 台电脑 同时 运行。
// 一开始，你可以给每台电脑连接 至多一个电池
// 然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作 任意次
// 新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池
// 断开连接和连接新的电池不会花费任何时间。
// 注意，你不能给电池充电。
// 请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
// 测试链接 : https://leetcode.cn/problems/maximum-running-time-of-n-computers/

class Solution1 {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int x : batteries){
            sum += x;
        }
        long long ans = 0;
        for(long long l = 0, r = sum, m; l <= r; ){
            m = (l + r) / 2;
            if(f1(n, batteries, m)){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return ans;
    }
    bool f1(int n, vector<int>& batteries, long long time){
        long long sum = 0;
        for(int x : batteries){
            if(x > time){
                n--;
            }else{
                sum += x;
            }
            if(sum >= n * time){
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int Max = 0;
        long long sum = 0;
        for(int x : batteries){
            Max = max(Max, x);
            sum += x;
        }
        if(sum > (long long) Max * n){
            return sum / n;
        }
        long long ans = 0;
        for(long long l = 0, r = Max, m; l <= r; ){
            m = (l + r) / 2;
            if(f2(n, batteries, m)){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return ans;
    }
    bool f2(int n, vector<int>& batteries, long long time){
        long long sum = 0;
        for(int x : batteries){
            if(x > time){
                n--;
            }else{
                sum += x;
            }
            if(sum >= n * time){
                return true;
            }
        }
        return false;
    }
};

int main(){

    return 0;
}
