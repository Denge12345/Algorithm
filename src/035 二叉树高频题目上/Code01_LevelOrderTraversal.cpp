#include <bits/stdc++.h>
using namespace std;

// 二叉树的层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-level-order-traversal/

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
    TreeNode* queue[2001];
    int l, r;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root != nullptr){
            l = r = 0;
            queue[r++] = root;
            while(l < r){
                int size = r - l;
                vector<int> vec;
                for(int i = 0; i < size; i++){
                    TreeNode* cur = queue[l++];
                    vec.push_back(cur->val);
                    if(cur->left != nullptr){
                        queue[r++] = cur->left;
                    }
                    if(cur->right != nullptr){
                        queue[r++] = cur->right;
                    }
                }
                ans.push_back(vec);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root != nullptr){
            queue<TreeNode*> q;
            unordered_map<TreeNode*, int> levels;
            q.push(root);
            levels[root] = 0;
            while(!q.empty()){
                TreeNode* cur = q.front();
                q.pop();
                int level = levels[cur];
                if(ans.size() == level){
                    ans.push_back(vector<int>());
                }
                ans[level].push_back(cur->val);
                if(cur->left != nullptr){
                    q.push(cur->left);
                    levels[cur->left] = level + 1;
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                    levels[cur->right] = level + 1;
                }
            }
        }
        return ans;
    }
};
*/

void printArray(vector<vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
    	for(int j = 0; j < arr[i].size(); j++){
    		cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node5 = new TreeNode(7);
    TreeNode* Node4 = new TreeNode(15);
    TreeNode* Node3 = new TreeNode(20, Node4, Node5);
    TreeNode* Node2 = new TreeNode(9);
    TreeNode* Node1 = new TreeNode(3, Node2, Node3);
    Solution solution;
    printArray(solution.levelOrder(Node1));
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node1 = new TreeNode(1);
    Solution solution;
    printArray(solution.levelOrder(Node1));
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node1 = nullptr;
    Solution solution;
    printArray(solution.levelOrder(Node1));
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
