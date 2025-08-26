#include <bits/stdc++.h>
using namespace std;

// 求完全二叉树的节点个数
// 测试链接 : https://leetcode.cn/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return f(root, 1, mostLeft(root, 1));
    }
    int f(TreeNode* cur, int level, int h){
        if(level == h){
            return 1;
        }
        if(mostLeft(cur->right, level + 1) == h){
            // 右子树的最左节点能到达最大深度(左子树是完全二叉树)
            return (1 << (h - level)) + f(cur->right, level + 1, h);
        }else{
            // 右子树的最左节点不能到达最大深度(右子树是完全二叉树)
            return (1 << (h - level - 1)) + f(cur->left, level + 1, h);
        }
    }
    // 当前节点为cur,它在第level层
    // 返回从cur不停往左,能到达第几层
    int mostLeft(TreeNode* cur, int level){
        while(cur != nullptr){
            level++;
            cur = cur->left;
        }
        return level - 1;
    }
};

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node6 = new TreeNode(6);
    TreeNode* Node5 = new TreeNode(5);
    TreeNode* Node4 = new TreeNode(4);
    TreeNode* Node3 = new TreeNode(3 ,Node6, nullptr);
    TreeNode* Node2 = new TreeNode(2, Node4, Node5);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    Solution solution;
    cout << solution.countNodes(Node1) << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    Solution solution;
    cout << solution.countNodes(nullptr) << endl;
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node1 = new TreeNode(1);
    Solution solution;
    cout << solution.countNodes(Node1) << endl;
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
