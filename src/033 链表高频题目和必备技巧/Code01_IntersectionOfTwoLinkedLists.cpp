#include <bits/stdc++.h>
using namespace std;

// 返回两个无环链表相交的第一个节点
// 测试链接 : https://leetcode.cn/problems/intersection-of-two-linked-lists/

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr){
        return nullptr;
    }
    // 分别表示两个链表的长度
    int Alen = 0, Blen = 0;
    // 计算两个链表的长度
    ListNode* tmp = headA;
    while(tmp != nullptr){
        Alen++;
        tmp = tmp->next;
    }
    tmp = headB;
    while(tmp != nullptr){
        Blen++;
        tmp = tmp->next;
    }
    // 长度之差
    int diff = abs(Alen - Blen);
    // 谁长让谁先走diff步,然后一起走,直到相遇
    if(Alen - Blen > 0){
        while(diff--){
            headA = headA->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
    }else if(Alen - Blen < 0){
        while(diff--){
            headB = headB->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
    }else{
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
    }
    return headA;
}

void test01(){
    cout << "=====测试1======" << endl;
    ListNode* Node8 = new ListNode(5, nullptr);
    ListNode* Node7 = new ListNode(4, Node8);
    ListNode* Node6 = new ListNode(8, Node7);
    ListNode* Node5 = new ListNode(1, Node6);
    ListNode* Node4 = new ListNode(6, Node5);
    ListNode* Node3 = new ListNode(5, Node4);
    ListNode* Node2 = new ListNode(1, Node6);
    ListNode* Node1 = new ListNode(4, Node2);
    cout << "链表1: ";
    printList(Node1);
    cout << "链表2: ";
    printList(Node3);
    ListNode* res = getIntersectionNode(Node1, Node3);
    cout << "相交的节点为: " << (res == nullptr ? 0 : res->val) << endl;
}

void test02(){
    cout << "=====测试2======" << endl;
    ListNode* Node6 = new ListNode(4, nullptr);
    ListNode* Node5 = new ListNode(2, Node6);
    ListNode* Node4 = new ListNode(3, Node5);
    ListNode* Node3 = new ListNode(1, Node5);
    ListNode* Node2 = new ListNode(9, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    cout << "链表1: ";
    printList(Node1);
    cout << "链表2: ";
    printList(Node4);
    ListNode* res = getIntersectionNode(Node1, Node4);
    cout << "相交的节点为: " << (res == nullptr ? 0 : res->val) << endl;
}

void test03(){
    cout << "=====测试3======" << endl;
    ListNode* Node5 = new ListNode(5, nullptr);
    ListNode* Node4 = new ListNode(1, Node5);
    ListNode* Node3 = new ListNode(4, nullptr);
    ListNode* Node2 = new ListNode(6, Node3);
    ListNode* Node1 = new ListNode(2, Node2);
    cout << "链表1: ";
    printList(Node1);
    cout << "链表2: ";
    printList(Node4);
    ListNode* res = getIntersectionNode(Node1, Node4);
    cout << "相交的节点为: " << (res == nullptr ? 0 : res->val) << endl;
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
