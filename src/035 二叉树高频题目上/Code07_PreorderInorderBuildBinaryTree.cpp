#include <bits/stdc++.h>
using namespace std;

// 利用先序与中序遍历序列构造二叉树
// 测试链接 : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()){
            return nullptr;
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return f(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
    TreeNode* f(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2, unordered_map<int, int>& mp){
        if(l1 > r1){
            return nullptr;
        }
        TreeNode* head = new TreeNode(preorder[l1]);
        if(l1 == r1){
            return head;
        }
        int k = mp[preorder[l1]];
        //k - l2表示左子树的节点个数
        //[l1, l1 + k - l2]表示左子树范围
        //[l1 + k - l2 + 1, r1]表示右子树范围
        //pre : l1(.....)[.....r1]
        //in  : (l2....)k[.....r2]
        head->left = f(preorder, l1 + 1, l1 + k - l2, inorder, l2, k - 1, mp);
        head->right = f(preorder, l1 + k - l2 + 1, r1, inorder, k + 1, r2, mp);
        return head;
    }
};

int main(){

    return 0;
}
