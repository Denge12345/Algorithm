#include <bits/stdc++.h>
using namespace std;

// 找出第K小的数对距离
// 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
// 给你一个整数数组 nums 和一个整数 k
// 数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
// 返回 所有数对距离中 第 k 小的数对距离。
// 测试链接 : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int l = 0, r = nums[n - 1] - nums[0], m, cnt; l <= r; ){
            m = (l + r) / 2;
            cnt = f(nums, m);
            if(cnt >= k){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
    int f(vector<int>& nums, int limit){
        int ans = 0;
        for(int l = 0, r = 0; l < nums.size(); l++){
            while(r + 1 < nums.size() && nums[r + 1] - nums[l] <= limit){
                r++;
            }
            ans += r - l;
        }
        return ans;
    }
};

int main(){

    return 0;
}
