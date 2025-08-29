#include <bits/stdc++.h>
using namespace std;

// 收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root != nullptr){
            vector<int> path;
            f(root, 0, targetSum, path, ans);
        }
        return ans;
    }
    void f(TreeNode* root, int sum, int target, vector<int>& path, vector<vector<int>>& ans){
        if(root->left == nullptr && root->right == nullptr){
            if(sum + root->val == target){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }else{
            path.push_back(root->val);
            if(root->left != nullptr){
                f(root->left, sum + root->val, target, path, ans);
            }
            if(root->right != nullptr){
                f(root->right, sum + root->val, target, path, ans);
            }
            path.pop_back();
        }
    }
};

void printArray(vector<vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node10 = new TreeNode(1);
    TreeNode* Node9 = new TreeNode(5);
    TreeNode* Node8 = new TreeNode(2);
    TreeNode* Node7 = new TreeNode(7);
    TreeNode* Node6 = new TreeNode(4, Node9, Node10);
    TreeNode* Node5 = new TreeNode(13);
    TreeNode* Node4 = new TreeNode(11, Node7, Node8);
    TreeNode* Node3 = new TreeNode(8, Node5, Node6);
    TreeNode* Node2 = new TreeNode(4, Node4, nullptr);
    TreeNode* Node1 = new TreeNode(5, Node2, Node3);
    int targetSum = 22;
    Solution solution;
    printArray(solution.pathSum(Node1, targetSum));
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node3 = new TreeNode(3);
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    int targetSum = 5;
    Solution solution;
    printArray(solution.pathSum(Node1, targetSum));
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(1, Node2, nullptr);
    int targetSum = 0;
    Solution solution;
    printArray(solution.pathSum(Node1, targetSum));
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
