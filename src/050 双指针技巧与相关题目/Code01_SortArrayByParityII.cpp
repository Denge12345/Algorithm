#include <bits/stdc++.h>
using namespace std;

// 按奇偶排序数组II
// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 你可以返回 任何满足上述条件的数组作为答案
// 测试链接 : https://leetcode.cn/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int even = 0, odd = 1; odd < n && even < n;){
            if((nums[n - 1] & 1) == 1){
                swap(nums[n - 1], nums[odd]);
                odd += 2;
            }else{
                swap(nums[n - 1], nums[even]);
                even += 2;
            }
        }
        return nums;
    }
};

int main(){

    return 0;
}
