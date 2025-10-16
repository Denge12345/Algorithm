#include <bits/stdc++.h>
using namespace std;

// 分割数组的最大值(画匠问题)
// 给定一个非负整数数组 nums 和一个整数 m
// 你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 测试链接 : https://leetcode.cn/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long sum = 0;
        for(int num : nums){
            sum += num;
        }
        long long ans = 0;
        for(long long l = 0, r = sum, m, need; l <= r; ){
            m = l + ((r - l) >> 1);
            need = f(nums, m);
            if(need <= k){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return (int)ans;
    }
    int f(vector<int>& nums, long long limit){
        int parts = 1;
        int sum = 0;
        for(int num : nums){
            if(num > limit){
                return INT_MAX;
            }else if(sum + num > limit){
                parts++;
                sum = num;
            }else{
                sum += num;
            }
        }
        return parts;
    }
};

int main(){

    return 0;
}
