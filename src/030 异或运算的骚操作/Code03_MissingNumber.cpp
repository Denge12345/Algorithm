#include <bits/stdc++.h>
using namespace std;

// 找到缺失的数字
// 测试链接 : https://leetcode.cn/problems/missing-number/

int missingNumber(vector<int>& nums) {
    int eorAll = 0, eorHas = 0, n = nums.size();
    for(int i = 0; i < n; i++){
        eorAll ^= i;
        eorHas ^= nums[i];
    }
    eorAll ^= n;
    return eorAll ^ eorHas;
}

int main(){
    vector<int> nums1 = {3, 0, 1};
    vector<int> nums2 = {0, 1};
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums1) << endl;
    cout << missingNumber(nums2) << endl;
    cout << missingNumber(nums3) << endl;
    return 0;
}
