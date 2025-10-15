#include <bits/stdc++.h>
using namespace std;

// 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
// 测试链接 : https://leetcode.cn/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r){
            if(nums[l] == l + 1){
                l++;
            }else if(nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]){
                swap(nums[l], nums[--r]);
            }else{
                swap(nums[l], nums[nums[l] - 1]);
            }
        }
        return l + 1;
    }
};

int main(){

    return 0;
}
