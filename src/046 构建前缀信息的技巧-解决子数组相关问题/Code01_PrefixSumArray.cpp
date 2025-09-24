#include <bits/stdc++.h>
using namespace std;

// 利用前缀和快速得到区域累加和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-immutable/

class NumArray {
public:
    int* prefix;
    NumArray(vector<int>& nums) {
        prefix = new int[nums.size() + 1];
        for(int i = 1; i <= nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main(){

    return 0;
}
