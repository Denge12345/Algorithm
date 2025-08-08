#include <bits/stdc++.h>
using namespace std;

// 数组中只有1种数出现次数少于m次，其他数都出现了m次
// 返回出现次数小于m次的那种数
// 测试链接 : https://leetcode.cn/problems/single-number-ii/

int cnts[32];

int find(vector<int>& nums, int m){
    for(int num : nums){
        for(int i = 0; i < 32; i++){
            cnts[i] += (num >> i) & 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < 32; i++){
        if(cnts[i] % m != 0){
            ans |= (1 << i);
        }
    }
    return ans;
}

int singleNumber(vector<int>& nums) {
    return find(nums, 3);
}

int main(){
    vector<int> nums1 = {2, 2, 3, 2};
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums1) << endl;
    cout << singleNumber(nums2) << endl;
    return 0;
}
