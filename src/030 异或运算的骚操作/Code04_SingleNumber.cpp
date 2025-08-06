#include <bits/stdc++.h>
using namespace std;

// 数组中1种数出现了奇数次，其他的数都出现了偶数次
// 返回出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number/

int singleNumber(vector<int>& nums) {
    int eor = 0;
    for(int num : nums){
        eor ^= num;
    }
    return eor;
}

int main(){
    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};
    cout << singleNumber(nums1) << endl;
    cout << singleNumber(nums2) << endl;
    cout << singleNumber(nums3) << endl;
    return 0;
}
