#include <bits/stdc++.h>
using namespace std;

// 数组中两个数的最大异或值
// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0<=i<=j<=n
// 1 <= nums.length <= 2 * 10^5
// 0 <= nums[i] <= 2^31 - 1
// 测试链接 : https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution1 {
public:
    int findMaximumXOR(vector<int>& nums) {
        build(nums);
        int ans = 0;
        for(int num : nums){
            ans = max(ans, maxXor(num));
        }
        clear();
        return ans;
    }
    int tree[3000001][2], cnt, high;
    void build(vector<int>& nums){
        cnt = 1;
        int Max = INT_MIN;
        for(int num : nums){
            Max = max(Max, num);
        }
        high = (Max == 0) ? 0 : 31 - __builtin_clz(Max);
        for(int num : nums){
            insert(num);
        }
    }
    void insert(int num){
        int cur = 1;
        for(int i = high, path; i >= 0; i--){
            path = (num >> i) & 1;
            if(tree[cur][path] == 0){
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
        }
    }
    void clear(){
        for(int i = 1; i <= cnt; i++){
            tree[i][0] = tree[i][1] = 0;
        }
    }
    int maxXor(int num){
        int ans = 0;
        int cur = 1;
        for(int i = high, status, want; i >= 0; i--){
            status = (num >> i) & 1;
            want = status ^ 1;
            if(tree[cur][want] == 0){
                want ^= 1;
            }
            ans |= (status ^ want) << i;
            cur = tree[cur][want];
        }
        return ans;
    }
};

class Solution2 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int Max = INT_MIN;
        for(int num : nums){
            Max = max(Max, num);
        }
        unordered_set<int> st;
        int ans = 0;
        for(int i = 31 - __builtin_clz(Max); i >= 0; i--){
            int better = ans | (1 << i);
            st.clear();
            for(int num : nums){
                num = (num >> i) << i;
                st.insert(num);
                if(st.count(better ^ num)){
                    ans = better;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
