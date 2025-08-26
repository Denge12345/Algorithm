#include <bits/stdc++.h>
using namespace std;

// 普通二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //p包含q,q包含p的情况
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q); //左子树是p或q的节点
        TreeNode* r = lowestCommonAncestor(root->right, p, q); //右子树是p或q的节点
        //p,q不是包含的情况,即在两个不同的子树中
        //左右子树两边都搜到了,返回根节点
        if(l != nullptr && r != nullptr){
            return root;
        }
        //左右子树两边都没搜到,返回空
        if(l == nullptr && r == nullptr){
            return nullptr;
        }
        //左右子树哪边搜到了返回哪边
        return l != nullptr ? l : r;
    }
};

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node9 = new TreeNode(4);
    TreeNode* Node8 = new TreeNode(7);
    TreeNode* Node7 = new TreeNode(8);
    TreeNode* Node6 = new TreeNode(0);
    TreeNode* Node5 = new TreeNode(2);
    TreeNode* Node4 = new TreeNode(6);
    TreeNode* Node3 = new TreeNode(1);
    TreeNode* Node2 = new TreeNode(5);
    TreeNode* Node1 = new TreeNode(3);
    Node5->left = Node8, Node5->right = Node9;
    Node3->left = Node6, Node3->right = Node7;
    Node2->left = Node4, Node2->right = Node5;
    Node1->left = Node2, Node1->right = Node3;
    Solution solution;
    TreeNode* p = Node5;
    TreeNode* q = Node1;
    cout << solution.lowestCommonAncestor(Node1, p, q)->val << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node9 = new TreeNode(4);
    TreeNode* Node8 = new TreeNode(7);
    TreeNode* Node7 = new TreeNode(8);
    TreeNode* Node6 = new TreeNode(0);
    TreeNode* Node5 = new TreeNode(2);
    TreeNode* Node4 = new TreeNode(6);
    TreeNode* Node3 = new TreeNode(1);
    TreeNode* Node2 = new TreeNode(5);
    TreeNode* Node1 = new TreeNode(3);
    Node5->left = Node8, Node5->right = Node9;
    Node3->left = Node6, Node3->right = Node7;
    Node2->left = Node4, Node2->right = Node5;
    Node1->left = Node2, Node1->right = Node3;
    Solution solution;
    TreeNode* p = Node5;
    TreeNode* q = Node4;
    cout << solution.lowestCommonAncestor(Node1, p, q)->val << endl;
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(1);
    Node1->left = Node2;
    Solution solution;
    TreeNode* p = Node1;
    TreeNode* q = Node2;
    cout << solution.lowestCommonAncestor(Node1, p, q)->val << endl;
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
