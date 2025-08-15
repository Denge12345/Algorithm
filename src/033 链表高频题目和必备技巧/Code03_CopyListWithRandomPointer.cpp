#include <bits/stdc++.h>
using namespace std;

// 复制带随机指针的链表
// 测试链接 : https://leetcode.cn/problems/copy-list-with-random-pointer/

//单链表节点
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//输出单链表
void printList(Node* head) {
    while (head != nullptr) {
        if(head->val >= 0) cout << head->val << "(" << (head->random == nullptr ? 0 : head->random->val) << ") -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* copyRandomList(Node* head) {
    if(head == nullptr){
        return head;
    }
    Node* cur = head;
    Node* next = nullptr;
    while(cur != nullptr){
        next = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = next;
        cur = next;
    }
    Node* copy = nullptr;
    cur = head;
    while(cur != nullptr){
        next = cur->next->next;
        copy = cur->next;
        copy->random = cur->random == nullptr ? nullptr : cur->random->next;
        cur = next;
    }
    Node* ans = head->next;
    cur = head;
    while(cur != nullptr){
        next = cur->next->next;
        copy = cur->next;
        cur->next = next;
        copy->next = next == nullptr ? nullptr : next->next;
        cur = next;
    }
    return ans;
}

void test01(){
    cout << "=====测试1=====" << endl;
    Node* Node5 = new Node(1);
    Node* Node4 = new Node(10);
    Node* Node3 = new Node(11);
    Node* Node2 = new Node(13);
    Node* Node1 = new Node(7);
    Node5->next = nullptr, Node5->random = Node1;
    Node4->next = Node5, Node4->random = Node3;
    Node3->next = Node4, Node3->random = nullptr;
    Node2->next = Node3, Node2->random = Node1;
    Node1->next = Node2, Node2->random = nullptr;
    cout << "链表: ";
    printList(Node1);
    cout << "新链表: ";
    printList(copyRandomList(Node1));
}

void test02(){
    cout << "=====测试2=====" << endl;
    Node* Node2 = new Node(2);
    Node* Node1 = new Node(1);
    Node2->next = nullptr,  Node2->random = Node2;
    Node1->next = Node2, Node1->random = Node2;
    cout << "链表: ";
    printList(Node1);
    cout << "新链表: ";
    printList(copyRandomList(Node1));
}

void test03(){
    cout << "=====测试3=====" << endl;
    Node* Node3 = new Node(3);
    Node* Node2 = new Node(3);
    Node* Node1 = new Node(3);
    Node3->next = nullptr, Node3->random = nullptr;
    Node2->next = Node3, Node2->random = Node1;
    Node1->next = Node2, Node1->random = nullptr;
    cout << "链表: ";
    printList(Node1);
    cout << "新链表: ";
    printList(copyRandomList(Node1));
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
