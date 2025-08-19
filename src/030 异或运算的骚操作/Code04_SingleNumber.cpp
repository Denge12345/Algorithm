#include <bits/stdc++.h>
using namespace std;

// 数组中1种数出现了奇数次，其他的数都出现了偶数次
// 返回出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number/
// 直接提交如下类即可
class Solution{
public:
    int singleNumber(vector<int>& nums) {
        int eor = 0;
        for(int num : nums){
            eor ^= num;
        }
        return eor;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};
    cout << solution.singleNumber(nums1) << endl;
    cout << solution.singleNumber(nums2) << endl;
    cout << solution.singleNumber(nums3) << endl;
    return 0;
}
