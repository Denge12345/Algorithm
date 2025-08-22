#include <bits/stdc++.h>
using namespace std;

// 求二叉树的最大、最小深度

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
    // 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    // 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        int ldeep = INT_MAX;
        int rdeep = INT_MAX;
        if(root->left != nullptr){
            ldeep = minDepth(root->left);
        }
        if(root->right != nullptr){
            rdeep = minDepth(root->right);
        }
        return min(ldeep, rdeep) + 1;
    }
};

void test01(){
    cout << "=====maxDepth测试1=====" << endl;
    TreeNode* Node5 = new TreeNode(7);
    TreeNode* Node4 = new TreeNode(15);
    TreeNode* Node3 = new TreeNode(20, Node4, Node5);
    TreeNode* Node2 = new TreeNode(9);
    TreeNode* Node1 = new TreeNode(3, Node2, Node3);
    Solution solution;
    cout << solution.maxDepth(Node1) << endl;
}
void test02(){
    cout << "=====maxDepth测试2=====" << endl;
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(1, nullptr, Node2);
    Solution solution;
    cout << solution.maxDepth(Node1) << endl;
}

void test03(){
    cout << "=====minDepth测试1=====" << endl;
    TreeNode* Node5 = new TreeNode(7);
    TreeNode* Node4 = new TreeNode(15);
    TreeNode* Node3 = new TreeNode(20, Node4, Node5);
    TreeNode* Node2 = new TreeNode(9);
    TreeNode* Node1 = new TreeNode(3, Node2, Node3);
    Solution solution;
    cout << solution.minDepth(Node1) << endl;
}

void test04(){
    cout << "=====minDepth测试2=====" << endl;
    TreeNode* Node5 = new TreeNode(6);
    TreeNode* Node4 = new TreeNode(5, nullptr, Node5);
    TreeNode* Node3 = new TreeNode(4, nullptr, Node4);
    TreeNode* Node2 = new TreeNode(3, nullptr, Node3);
    TreeNode* Node1 = new TreeNode(2, nullptr, Node2);
    Solution solution;
    cout << solution.minDepth(Node1) << endl;
}

int main(){
    test01();
    test02();
    test03();
    test04();
    return 0;
}
