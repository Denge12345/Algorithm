#include <bits/stdc++.h>
using namespace std;

// 数组中有2种数出现了奇数次，其他的数都出现了偶数次
// 返回这2种出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number-iii/

vector<int> singleNumber(vector<int>& nums) {
    long long eor1 = 0;
    for(int num : nums){
        eor1 ^= num;
    }
    long long rightOne = eor1 & (-eor1);
    long long eor2 = 0;
    for(int num : nums){
        if((num & rightOne) == 0){
            eor2 ^= num;
        }
    }
    return {(int)eor2, (int)(eor1 ^ eor2)};
}

int main(){
    vector<int> nums1 = {1, 2, 1, 3, 2, 5};
    vector<int> nums2 = {-1, 0};
    vector<int> nums3 = {0, 1};
    for(int num : singleNumber(nums1)) cout << num << " ";
    cout << endl;
    for(int num : singleNumber(nums2)) cout << num << " ";
    cout << endl;
    for(int num : singleNumber(nums3)) cout << num << " ";
    cout << endl;
    return 0;
}
