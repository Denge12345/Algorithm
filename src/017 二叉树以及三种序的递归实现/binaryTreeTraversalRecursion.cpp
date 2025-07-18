#include <bits/stdc++.h>
using namespace std;

//树节点
class TreeNode{
    public:
    TreeNode(int val, TreeNode* l, TreeNode* r) : val(val), left(l), right(r) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

void preOrder1(TreeNode* head){
    if(head == nullptr){
        return;
    }
    cout << head->val << " ";
    preOrder1(head->left);
    preOrder1(head->right);
}

void inOrder1(TreeNode* head){
    if(head == nullptr){
        return;
    }
    inOrder1(head->left);
    cout << head->val << " ";
    inOrder1(head->right);
}

void posOrder1(TreeNode* head){
    if(head == nullptr){
        return;
    }
    posOrder1(head->left);
    posOrder1(head->right);
    cout << head->val << " ";
}

void preOrder2(int head, int ls[], int rs[]){
    if(head == 0){
        return;
    }
    cout << head << " ";
    preOrder2(ls[head], ls, rs);
    preOrder2(rs[head], ls, rs);
}

void inOrder2(int head, int ls[], int rs[]){
    if(head == 0){
        return;
    }
    inOrder2(ls[head], ls, rs);
    cout << head << " ";
    inOrder2(rs[head], ls, rs);
}

void posOrder2(int head, int ls[], int rs[]){
    if(head == 0){
        return;
    }
    posOrder2(ls[head], ls, rs);
    cout << head << " ";
    posOrder2(rs[head], ls, rs);
}

void testTreeTraversal1(){
    cout << "===类实现二叉树以及三种序的递归===" << endl;
    TreeNode* Node7 = new TreeNode(7, nullptr, nullptr);
    TreeNode* Node6 = new TreeNode(6, nullptr, nullptr);
    TreeNode* Node5 = new TreeNode(5, nullptr, nullptr);
    TreeNode* Node4 = new TreeNode(4, nullptr, nullptr);
    TreeNode* Node3 = new TreeNode(3, Node6, Node7);
    TreeNode* Node2 = new TreeNode(2, Node4, Node5);
    TreeNode* head = new TreeNode(1, Node2, Node3);
    cout << "先序遍历" << endl;
    preOrder1(head);
    cout << endl;
    cout << "中序遍历" << endl;
    inOrder1(head);
    cout << endl;
    cout << "后序遍历" << endl;
    posOrder1(head); 
    cout << endl;
}

void testTreeTraversal2(){
    cout << "===数组实现二叉树以及三种序的递归===" << endl;
    //数组下标表示父节点,ls表示左儿子,rs表示右儿子
    //数组中存储的值表示节点的值
    int ls[10] = {0};
    int rs[10] = {0};
    ls[1] = 2, rs[1] = 3;
    ls[2] = 4, rs[2] = 5;
    ls[3] = 6, rs[3] = 7;
    cout << "先序遍历" << endl;
    preOrder2(1, ls, rs);
    cout << endl;
    cout << "中序遍历" << endl;
    inOrder2(1, ls, rs);
    cout << endl;
    cout << "后序遍历" << endl;
    posOrder2(1, ls, rs);
}

int main(){
    testTreeTraversal1();
    testTreeTraversal2();
    return 0;
}
