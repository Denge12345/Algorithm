#include <bits/stdc++.h>
using namespace std;

// 完成旅途的最少时间(题目6的在线测试)
// 有同学找到了在线测试链接，和课上讲的题目6几乎是一个意思，但是有细微差别
// 实现的代码，除了一些变量需要改成long类型之外，仅有两处关键逻辑不同，都打上了注释
// 除此之外，和课上讲的题目6的实现，再无区别
// 可以仔细阅读如下测试链接里的题目，重点关注此题和题目6，在题意上的差别
// 测试链接 : https://leetcode.cn/problems/minimum-time-to-complete-trips/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int Min = INT_MAX;
        for(int x : time){
          Min = min(Min, x);
        }
        long long ans = 0;
        for(long long l = 0, r = 1ll * Min * totalTrips, m; l <= r; ){
          m = l + (r - l) / 2;
          if(f(time, m) >= totalTrips){
            ans = m;
            r = m - 1;
          }else{
            l = m + 1;
          }
        }
        return ans;
    }
    long long f(vector<int>& time, long long Time){
      long long ans = 0;
      for(int num : time){
        ans += (Time / num);
      }
      return ans;
    }
};

int main(){

    return 0;
}
