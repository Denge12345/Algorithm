#include <bits/stdc++.h>
using namespace std;

// 修剪搜索二叉树
// 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 直接提交如下类即可
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return nullptr;
        }
        //去右树搜索
        if(root->val < low){
            return trimBST(root->right, low, high);
        }
        //去左树搜索
        if(root->val > high){
            return trimBST(root->left, low, high);
        }
        //root->val在[low,high]中
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

int main(){

    return 0;
}
