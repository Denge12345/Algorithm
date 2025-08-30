#include <bits/stdc++.h>
using namespace std;

// 验证平衡二叉树
// 测试链接 : https://leetcode.cn/problems/balanced-binary-tree/

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 提交如下类即可
class Solution {
public:
    bool balance;
    bool isBalanced(TreeNode* root) {
        balance = true;
        height(root);
        return balance;
    }
    int height(TreeNode* root){
        if(!balance || root == nullptr){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) > 1){
            balance = false;
        }
        return max(lh, rh) + 1;
    }
};

int main(){

    return 0;
}
