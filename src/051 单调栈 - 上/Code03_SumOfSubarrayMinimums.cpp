#include <bits/stdc++.h>
using namespace std;

// 子数组的最小值之和
// 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/sum-of-subarray-minimums/

class Solution {
public:
    int mod = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), r = 0;
        vector<int> stk(n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            while(r > 0 && arr[stk[r - 1]] >= arr[i]){
                int cur = stk[--r];
                int left = r == 0 ? -1 : stk[r - 1];
                ans = (ans + 1ll * (cur - left) * (i - cur) * arr[cur]) % mod;
            }
            stk[r++] = i;
        }
        while(r > 0){
            int cur = stk[--r];
            int left = r == 0 ? -1 : stk[r - 1];
            ans = (ans + 1ll * (cur - left) * (n - cur) * arr[cur]) % mod;
        }
        return (int)ans;
    }
};

int main(){
    
    return 0;
}
