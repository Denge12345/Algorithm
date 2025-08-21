#include <bits/stdc++.h>
using namespace std;

// 二叉树的锯齿形层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root != nullptr){
            l = r = 0;
            queue[r++] = root;
            bool rev = false; //是否逆序遍历
            while(l < r){
                int size = r - l;
                vector<int> vec;
                for(int i = rev ? r - 1 : l, j = rev ? -1 : 1, k = 0; k < size; i += j, k++){
                    vec.push_back(queue[i]->val);
                }
                for(int i = 0; i < size; i++){
                    TreeNode* cur = queue[l++];
                    if(cur->left != nullptr){
                        queue[r++] = cur->left;
                    }
                    if(cur->right != nullptr){
                        queue[r++] = cur->right;
                    }
                }
                ans.push_back(vec);
                rev = !rev;
            }
        }
        return ans;
    }
};

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
    printArray(solution.zigzagLevelOrder(Node1));
}

void test02(){
    cout << "=====测试2=====" << endl;
    TreeNode* Node1 = new TreeNode(1);
    Solution solution;
    printArray(solution.zigzagLevelOrder(Node1));
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node1 = nullptr;
    Solution solution;
    printArray(solution.zigzagLevelOrder(Node1));
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
