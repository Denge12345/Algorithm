#include <bits/stdc++.h>
using namespace std;

// 绝对差不超过限制的最长连续子数组
// 给你一个整数数组 nums ，和一个表示限制的整数 limit
// 请你返回最长连续子数组的长度
// 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
// 如果不存在满足条件的子数组，则返回 0
// 测试链接 : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    vector<int> maxDeque = vector<int>(100009);
    vector<int> minDeque = vector<int>(100009);
    vector<int> arr;
    int maxh, minh, maxt, mint;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        maxh = minh = maxt = mint = 0;
        arr = nums;
        int ans = 0;
        for(int l = 0, r = 0; l < n; l++){
            // r 不越界且满足题意就一直往右扩充
            while(r < n && ok(limit, nums[r])){
                push(r++);
            }
            // 记录答案
            ans = max(ans, r - l);
            // 往左收缩
            pop(l);
        }
        return ans;
    }
    // 最大值 - 最小值是否 <= limit
    bool ok(int limit, int number){
        int Max = maxh < maxt ? max(arr[maxDeque[maxh]], number) : number;
        int Min = minh < mint ? min(arr[minDeque[minh]], number) : number;
        return Max - Min <= limit;
    }
    void push(int r){
        while(maxh < maxt && arr[maxDeque[maxt - 1]] <= arr[r]){
            maxt--;
        }
        maxDeque[maxt++] = r;
        while(minh < mint && arr[minDeque[mint - 1]] >= arr[r]){
            mint--;
        }
        minDeque[mint++] = r;
    }
    void pop(int l){
        if(maxh < maxt && maxDeque[maxh] == l){
            maxh++;
        }
        if(minh < mint && minDeque[minh] == l){
            minh++;
        }
    }
};

int main(){

    return 0;
}
