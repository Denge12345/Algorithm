#include <bits/stdc++.h>
using namespace std;

// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
// 注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 测试链接 : https://leetcode.cn/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path(nums.size());
        sort(nums.begin(), nums.end());
        f(nums, 0, path, 0, ans);
        return ans;
    }
    void f(vector<int>& nums, int i, vector<int>& path, int size, vector<vector<int>>& ans){
        if(i == nums.size()){
            vector<int> cur;
            for(int j = 0; j < size; j++){
                cur.push_back(path[j]);
            }
            ans.push_back(cur);
        }else{
            int j = i + 1;
            while(j < nums.size() && nums[i] == nums[j]){
                j++;
            }
            // 当前数x,放0个
            f(nums, j, path, size, ans);
            // 当前数x,放1个,放2个...
            for(; i < j; i++){
                path[size++] = nums[i];
                f(nums, j, path, size, ans);
            }
        }
    }
};

int main(){

    return 0;
}
