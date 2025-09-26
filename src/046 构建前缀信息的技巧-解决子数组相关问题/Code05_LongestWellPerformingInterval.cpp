#include <bits/stdc++.h>
using namespace std;

// 表现良好的最长时间段
// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
// 请你返回 表现良好时间段 的最大长度
// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0, sum = 0; i < hours.size(); i++){
            sum += hours[i] > 8 ? 1 : -1;
            if(sum > 0){
                ans = i + 1;
            }else{
                if(mp.count(sum - 1)){
                    ans = max(ans, i - mp[sum - 1]);
                }
            }
            if(!mp.count(sum)){
                mp[sum] = i;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}