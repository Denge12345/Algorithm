#include <bits/stdc++.h>
using namespace std;

// 验证完全二叉树
// 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/

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
    TreeNode* queue[101];
    int l, r;
    bool isCompleteTree(TreeNode* root) {
        //判断是否是完全二叉树
        //1.如果没有遇到非满节点,一个节点只有右节点,不是完全二叉树
        //2.如果遇到非满节点,剩下的节点有左节点或右节点,不是完全二叉树
        if(root == nullptr){
            return true;
        }
        l = r = 0;
        queue[r++] = root;
        //是否遇到第一个非满节点
        bool leaf = false;
        while(l < r){
            TreeNode* cur = queue[l++];
            if((cur->left == nullptr && cur->right != nullptr) || (leaf && (cur->left != nullptr || cur->right != nullptr))){
                return false;
            }
            if(cur->left != nullptr){
                queue[r++] = cur->left;
            }
            if(cur->right != nullptr){
                queue[r++] = cur->right;
            }
            if(cur->left == nullptr || cur->right == nullptr){
                leaf = true;
            }
        }
        return true;
    }
};

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node6 = new TreeNode(6);
    TreeNode* Node5 = new TreeNode(5);
    TreeNode* Node4 = new TreeNode(4);
    TreeNode* Node3 = new TreeNode(3, Node6, nullptr);
    TreeNode* Node2 = new TreeNode(2, Node4, Node5);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    Solution solution;
    cout << solution.isCompleteTree(Node1) << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node6 = new TreeNode(7);
    TreeNode* Node5 = new TreeNode(5);
    TreeNode* Node4 = new TreeNode(4);
    TreeNode* Node3 = new TreeNode(3, nullptr, Node6);
    TreeNode* Node2 = new TreeNode(2, Node4, Node5);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    Solution solution;
    cout << solution.isCompleteTree(Node1) << endl;
}

int main(){
    test01();
    test02();
    return 0;
}
