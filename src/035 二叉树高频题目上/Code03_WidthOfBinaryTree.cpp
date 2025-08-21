#include <bits/stdc++.h>
using namespace std;

// 二叉树的最大特殊宽度
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/

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
    TreeNode* nq[3001];
    unsigned long long iq[3001];
    int l, r;
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1;
        l = r = 0;
        nq[r] = root;
        iq[r++] = 1ull;
        while(l < r){
            int size = r - l;
            ans = max(ans, static_cast<int>(iq[r - 1] - iq[l] + 1));
            for(int i = 0; i < size; i++){
                TreeNode* cur = nq[l];
                unsigned long long id = iq[l++];
                if(cur->left != nullptr){
                    nq[r] = cur->left;
                    iq[r++] = 2ull * id;
                }
                if(cur->right != nullptr){
                    nq[r] = cur->right;
                    iq[r++] = 2ull * id + 1ull;
                }
            }
        }
        return ans;
    }
};

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node6 = new TreeNode(9);
    TreeNode* Node5 = new TreeNode(3);
    TreeNode* Node4 = new TreeNode(5);
    TreeNode* Node3 = new TreeNode(2, nullptr, Node6);
    TreeNode* Node2 = new TreeNode(3, Node4, Node5);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    Solution solution;
    cout << solution.widthOfBinaryTree(Node1) << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node7 = new TreeNode(7);
    TreeNode* Node6 = new TreeNode(9);
    TreeNode* Node5 = new TreeNode(9, Node7, nullptr);
    TreeNode* Node4 = new TreeNode(5, Node6, nullptr);
    TreeNode* Node3 = new TreeNode(2, nullptr, Node5);
    TreeNode* Node2 = new TreeNode(3, Node4, nullptr);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    Solution solution;
    cout << solution.widthOfBinaryTree(Node1) << endl;
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node4 = new TreeNode(5);
    TreeNode* Node3 = new TreeNode(2);
    TreeNode* Node2 = new TreeNode(3, Node4, nullptr);
    TreeNode* Node1 = new TreeNode(1, Node2, Node3);
    Solution solution;
    cout << solution.widthOfBinaryTree(Node1) << endl;
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
