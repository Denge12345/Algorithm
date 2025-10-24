#include <bits/stdc++.h>
using namespace std;

// 每日温度
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 测试链接 : https://leetcode.cn/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int r = 0;
        vector<int> ans(n), stk(n + 1);
        for(int i = 0; i < n; i++){
            while(r > 0 && temperatures[stk[r - 1]] < temperatures[i]){
                int cur = stk[--r];
                ans[cur] = i - cur; 
            }
            stk[r++] = i;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
