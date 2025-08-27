#include <bits/stdc++.h>
using namespace std;

// 搜索二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
        // root从上到下
		// 如果先遇到了p，说明p是答案
		// 如果先遇到了q，说明q是答案
		// 如果root在p~q的值之间，不用管p和q谁大谁小，只要root在中间，那么此时的root就是答案
		// 如果root在p~q的值的左侧，那么root往右移动
		// 如果root在p~q的值的右侧，那么root往左移动
        while(root->val != p->val && root->val != q->val){
            if(root->val > min(p->val, q->val) && root->val < max(p->val, q->val)){
                break;
            }
            root = root->val < min(p->val, q->val) ? root->right : root->left;
        }
        return root;
    }
};

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node9 = new TreeNode(5);
    TreeNode* Node8 = new TreeNode(3);
    TreeNode* Node7 = new TreeNode(9);
    TreeNode* Node6 = new TreeNode(7);
    TreeNode* Node5 = new TreeNode(4);
    TreeNode* Node4 = new TreeNode(0);
    TreeNode* Node3 = new TreeNode(8);
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(6);
    Node5->left = Node8, Node5->right = Node9;
    Node3->left = Node6, Node3->right = Node7;
    Node2->left = Node4, Node2->right = Node5;
    Node1->left = Node2, Node1->right = Node3;
    Solution solution;
    TreeNode* p = Node2;
    TreeNode* q = Node3;
    cout << solution.lowestCommonAncestor(Node1, p, q)->val << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node9 = new TreeNode(5);
    TreeNode* Node8 = new TreeNode(3);
    TreeNode* Node7 = new TreeNode(9);
    TreeNode* Node6 = new TreeNode(7);
    TreeNode* Node5 = new TreeNode(4);
    TreeNode* Node4 = new TreeNode(0);
    TreeNode* Node3 = new TreeNode(8);
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(6);
    Node5->left = Node8, Node5->right = Node9;
    Node3->left = Node6, Node3->right = Node7;
    Node2->left = Node4, Node2->right = Node5;
    Node1->left = Node2, Node1->right = Node3;
    Solution solution;
    TreeNode* p = Node2;
    TreeNode* q = Node5;
    cout << solution.lowestCommonAncestor(Node1, p, q)->val << endl;
}

int main(){
    test01();
    test02();
    return 0;
}
