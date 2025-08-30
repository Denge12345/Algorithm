#include <bits/stdc++.h>
using namespace std;

// 验证搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 请将类名修改为Solution后提交
class Solution1 {
public:
    TreeNode* stk[10001];
    int r;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        TreeNode* pre = nullptr;
        r = 0;
        while(r > 0 || root != nullptr){
            if(root != nullptr){
                stk[r++] = root;
                root = root->left;
            }else{
                root = stk[--r];
                if(pre != nullptr && pre->val >= root->val){
                    return false;
                }
                pre = root;
                root = root->right;
            }
        }
        return true;
    }
};

// 请将类名修改为Solution后提交
class Solution2 {
public:
    long long Min, Max;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            Min = LONG_MAX;
            Max = LONG_MIN;
            return true;
        }
        bool lok = isValidBST(root->left);
        long long lmin = Min;
        long long lmax = Max;
        bool rok = isValidBST(root->right);
        long long rmin = Min;
        long long rmax = Max;
        Min = min(min(lmin, rmin), root->val);
        Max = max(max(lmax, rmax), root->val);
        return lok && rok && lmax < root->val && rmin > root->val;
    }
};

int main(){

    return 0;
}
