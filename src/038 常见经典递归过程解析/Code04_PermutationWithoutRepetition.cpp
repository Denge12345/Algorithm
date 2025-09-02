#include <bits/stdc++.h>
using namespace std;

// 有重复项数组的去重全排列
// 测试链接 : https://leetcode.cn/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums, 0, ans);
        return ans;    
    }
    void f(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(nums);
        }else{
            set<int> st;
            for(int j = i; j < nums.size(); j++){
                if(!st.count(nums[j])){
                    st.insert(nums[j]);
                    swap(nums[i], nums[j]);
                    f(nums, i + 1, ans);
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};

int main(){

    return 0;
}
