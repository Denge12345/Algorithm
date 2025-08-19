#include <bits/stdc++.h>
using namespace std;

// 找到缺失的数字
// 测试链接 : https://leetcode.cn/problems/missing-number/
// 直接提交如下类即可
class Solution{
public:
    int missingNumber(vector<int>& nums) {
        int eorAll = 0, eorHas = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            eorAll ^= i;
            eorHas ^= nums[i];
        }
        eorAll ^= n;
        return eorAll ^ eorHas;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {3, 0, 1};
    vector<int> nums2 = {0, 1};
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << solution.missingNumber(nums1) << endl;
    cout << solution.missingNumber(nums2) << endl;
    cout << solution.missingNumber(nums3) << endl;
    return 0;
}
