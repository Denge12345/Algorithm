#include<bits/stdc++.h>
using namespace std;

//树节点
class TreeNode{
    public:
    TreeNode(int val, TreeNode* l, TreeNode* r) : val(val), left(l), right(r) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

void preOrder(TreeNode* head){
    if(head != nullptr){
        stack<TreeNode*> stk;
        stk.push(head);
        while(!stk.empty()){
            head = stk.top();
            stk.pop();
            cout << head->val << " ";
            if(head->right != nullptr){
                stk.push(head->right);
            }
            if(head->left != nullptr){
                stk.push(head->left);
            }
        }
    }
    cout << endl;
}

void inOrder(TreeNode* head){
    if(head != nullptr){
        stack<TreeNode*> stk;
        while(!stk.empty() || head != nullptr){
            if(head != nullptr){
                stk.push(head);
                head = head->left;
            }else{
                head = stk.top();
                stk.pop();
                cout << head->val << " ";
                head = head->right;
            }
        }
    }
    cout << endl;
}

void posOrder1(TreeNode* head){
    if(head != nullptr){
        stack<TreeNode*> stk;
        stack<TreeNode*> out;
        stk.push(head);
        while(!stk.empty()){
            head = stk.top();
            stk.pop();
            out.push(head);
            if(head->left != nullptr){
                stk.push(head->left);
            }
            if(head->right != nullptr){
                stk.push(head->right);
            }
        }
        while(!out.empty()){
            cout << out.top()->val << " ";
            out.pop();
        }
    }
    cout << endl;
}

void posOrder2(TreeNode* head){
    if(head != nullptr){
        stack<TreeNode*> stk;
        stk.push(head);
        //head表示上一次打印的节点
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            if(cur->left != nullptr && head != cur->left && head != cur->right){
                //有左子树且没有处理
                stk.push(cur->left);
            }else if(cur->right != nullptr && head != cur->right){
                //有右子树且没有处理
                stk.push(cur->right);
            }else{
                //没有左子树右子树或全部处理
                cout << stk.top()->val << " ";
                head = stk.top();
                stk.pop();
            }
        }
    }
}

// 用一个栈完成先序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-preorder-traversal/
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root != nullptr){
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            if(root->right != nullptr){
                stk.push(root->right);
            }
            if(root->left != nullptr){
                stk.push(root->left);
            }
        }
    }
    return ans; 
}

// 用一个栈完成中序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-inorder-traversal/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root != nullptr){
        stack<TreeNode*> stk;
        while(!stk.empty() || root != nullptr){
            if(root != nullptr){
                stk.push(root);
                root = root->left;
            }else{
                root = stk.top();
                stk.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
    }
    return ans;
}

// 两个栈实现后序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
vector<int> postorderTraversal1(TreeNode* root) {
    vector<int> ans;
    if(root != nullptr){
        stack<TreeNode*> stk;
        stack<TreeNode*> out;
        stk.push(root);
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            out.push(root);
            if(root->left != nullptr){
                stk.push(root->left);
            }
            if(root->right != nullptr){
                stk.push(root->right);
            }
        }
        while(!out.empty()){
            ans.push_back(out.top()->val);
            out.pop();
        }
    }
    return ans;
}

// 用一个栈完成后序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
vector<int> postorderTraversal2(TreeNode* root) {
    vector<int> ans;
    if(root != nullptr){
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            if(cur->left != nullptr && root != cur->left && root != cur->right){
                stk.push(cur->left);
            }else if(cur->right != nullptr && root != cur->right){
                stk.push(cur->right);
            }else{
                ans.push_back(stk.top()->val);
                root = stk.top();
                stk.pop();
            }
        }
    }
    return ans;
}

void testTreeTraversal1(){
    cout << "===自行测试===" << endl;
    TreeNode* Node7 = new TreeNode(7, nullptr, nullptr);
    TreeNode* Node6 = new TreeNode(6, nullptr, nullptr);
    TreeNode* Node5 = new TreeNode(5, nullptr, nullptr);
    TreeNode* Node4 = new TreeNode(4, nullptr, nullptr);
    TreeNode* Node3 = new TreeNode(3, Node6, Node7);
    TreeNode* Node2 = new TreeNode(2, Node4, Node5);
    TreeNode* head = new TreeNode(1, Node2, Node3);
    cout << "先序遍历" << endl;
    preOrder(head);
    cout << "中序遍历" << endl;
    inOrder(head);
    cout << "后序遍历 - 两个栈实现" << endl;
    posOrder1(head);
    cout << "后序遍历 - 一个栈实现" << endl;
    posOrder2(head);
}

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void testTreeTraversal2(){
    cout << "===leetcode测试===" << endl;
    TreeNode* Node7 = new TreeNode(7, nullptr, nullptr);
    TreeNode* Node6 = new TreeNode(6, nullptr, nullptr);
    TreeNode* Node5 = new TreeNode(5, nullptr, nullptr);
    TreeNode* Node4 = new TreeNode(4, nullptr, nullptr);
    TreeNode* Node3 = new TreeNode(3, Node6, Node7);
    TreeNode* Node2 = new TreeNode(2, Node4, Node5);
    TreeNode* head = new TreeNode(1, Node2, Node3);
    cout << "先序遍历" << endl;
    printVector(preorderTraversal(head));
    cout << "中序遍历" << endl;
    printVector(inorderTraversal(head));
    cout << "后续遍历 - 两个栈实现" << endl;
    printVector(postorderTraversal1(head));
    cout << "后序遍历 - 一个栈实现" << endl;
    printVector(postorderTraversal2(head));
}

int main(){
    testTreeTraversal1();
    cout << endl;
    testTreeTraversal2();
    return 0;
}
