#include <bits/stdc++.h>
using namespace std;

// 二叉树打家劫舍问题
// 测试链接 : https://leetcode.cn/problems/house-robber-iii/

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

    int yes, no;
    // yes表示完成X子树的遍历后,偷X子树的头节点所获得的最大收益
    // no表示完成X子树的遍历后,不偷X子树的头节点所获得的最大收益
    int rob(TreeNode* root) {
        f(root);
        return max(yes, no);
    }
    void f(TreeNode* root){
        if(root == nullptr){
            yes = 0;
            no = 0;
        }else{
            //偷当前节点所获得的最大收益
            int y = root->val;
            //不偷当前节点所获得的最大收益
            int n = 0;
            f(root->left);
            y += no;
            n += max(yes, no);
            f(root->right);
            y += no;
            n += max(yes, no);
            yes = y;
            no = n;
        }
    }
};

int main(){

    return 0;
}
