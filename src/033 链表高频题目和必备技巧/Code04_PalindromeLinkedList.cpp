#include <bits/stdc++.h>
using namespace std;

// 判断链表是否是回文结构
// 测试链接 : https://leetcode.cn/problems/palindrome-linked-list/

//单链表节点
class ListNode{
    public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
    int val;
    ListNode* next;
};

//输出单链表
void printList(ListNode* head) {
    while (head != nullptr) {
        if(head->val >= 0) cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* pre = slow;
    ListNode* cur = pre->next;
    ListNode* next = nullptr;
    pre->next = nullptr;
    while(cur != nullptr){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    bool ans = true;
    ListNode* left = head;
    ListNode* right = pre;
    while(left != nullptr && right != nullptr){
        if(left->val != right->val){
            ans = false;
            break;
        }
        left = left->next;
        right = right->next;
    }
    cur = pre->next;
    pre->next = nullptr;
    next = nullptr;
    while(cur != nullptr){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return ans;
}

void test01(){
    cout << "=====测试1=====" << endl;
    ListNode* Node4 = new ListNode(1, nullptr);
    ListNode* Node3 = new ListNode(2, Node4);
    ListNode* Node2 = new ListNode(2, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    cout << "链表: ";
    printList(Node1);
    cout << "是否为回文链表: " << isPalindrome(Node1) << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    ListNode* Node2 = new ListNode(2, nullptr);
    ListNode* Node1 = new ListNode(1, Node2);
    cout << "链表: ";
    printList(Node1);
    cout << "是否为回文链表: " << isPalindrome(Node1) << endl;
}

int main(){
    test01();
    test02();
    return 0;
}
