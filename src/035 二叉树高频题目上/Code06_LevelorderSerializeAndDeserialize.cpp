#include <bits/stdc++.h>
using namespace std;

// 二叉树按层序列化和反序列化
// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    TreeNode* queue[10001];
    int l, r;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializeString = "";
        if(root != nullptr){
            serializeString += to_string(root->val) + ',';
            l = r = 0;
            queue[r++] = root;
            while(l < r){
                TreeNode* root = queue[l++];
                if(root->left != nullptr){
                    serializeString += to_string(root->left->val) + ',';
                    queue[r++] = root->left;
                }else{
                    serializeString += "None,";
                }
                if(root->right != nullptr){
                    serializeString += to_string(root->right->val) + ',';
                    queue[r++] = root->right;
                }else{
                    serializeString += "None,";
                }
            }
        }
        return serializeString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        vector<string> dataArray;
        string str;
        for(auto& ch : data){
            if(ch == ','){
                dataArray.push_back(str);
                str.clear();
            }else{
                str.push_back(ch);
            }
        }
        //如果最后一个还有内容
        if(!str.empty()){
            dataArray.push_back(str);
            str.clear();
        }
        int index = 0;
        TreeNode* root = generate(dataArray[index++]);
        l = r = 0;
        queue[r++] = root;
        while(l < r){
            TreeNode* cur = queue[l++];
            cur->left = generate(dataArray[index++]);
            cur->right = generate(dataArray[index++]);
            if(cur->left != nullptr){
                queue[r++] = cur->left;
            }
            if(cur->right != nullptr){
                queue[r++] = cur->right;
            }
        }
        return root;
    }
    TreeNode* generate(string val){
        return val == "None" ? nullptr : new TreeNode(stoi(val));
    }
};

void test01(){
    cout << "=====测试1=====" << endl;
    TreeNode* Node5 = new TreeNode(5);
    TreeNode* Node4 = new TreeNode(4);
    TreeNode* Node3 = new TreeNode(3);
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(1);
    Node1->left = Node2, Node1->right = Node3;
    Node3->left = Node4, Node3->right = Node5;
    Codec solution;
    cout << solution.serialize(Node1) << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    Codec solution;
    cout << solution.serialize(nullptr) << endl;
}

void test03(){
    cout << "=====测试3=====" << endl;
    TreeNode* Node1 = new TreeNode(1);
    Codec solution;
    cout << solution.serialize(Node1) << endl;
}

void test04(){
    cout << "=====测试4=====" << endl;
    TreeNode* Node2 = new TreeNode(2);
    TreeNode* Node1 = new TreeNode(1);
    Node1->left = Node2;
    Codec solution;
    cout << solution.serialize(Node1) << endl;
}

int main(){
    test01();
    test02();
    test03();
    test04();
    return 0;
}
