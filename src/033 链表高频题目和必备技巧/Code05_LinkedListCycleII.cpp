#include <bits/stdc++.h>
using namespace std;

// 返回链表的第一个入环节点
// 测试链接 : https://leetcode.cn/problems/linked-list-cycle-ii/

//单链表节点
class ListNode{
    public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next, int pos) : val(val), next(next), pos(pos) {}
    int val;
    int pos;
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

ListNode *detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return nullptr;
    }
    //slow指针一次走一步,fast指针一次走两步
    ListNode* slow = head->next;
    ListNode* fast = head->next->next;
    while(fast != slow){
        if(fast->next == nullptr || fast->next->next == nullptr){
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    //相遇后fast指针回到开头,两个指针一次走一步
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    //再次相遇后就是结果
    return slow;
}

void test01(){
    cout << "=====测试1=====" << endl;
    ListNode* Node4 = new ListNode(-4);
    ListNode* Node3 = new ListNode(0, Node4, 2);
    ListNode* Node2 = new ListNode(2, Node3, 1);
    ListNode* Node1 = new ListNode(3, Node2, 0);
    Node4->next = Node2, Node4->pos = 3;
    cout << "入环节点为: " << detectCycle(Node1)->pos << endl;
}

void test02(){
    cout << "=====测试2=====" << endl;
    ListNode* Node2 = new ListNode(2);
    ListNode* Node1 = new ListNode(1, Node2, 0);
    Node2->next = Node1, Node2->pos = 1;
    cout << "入环节点为: " << detectCycle(Node1)->pos << endl;
}

void test03(){
    cout << "=====测试3=====" << endl;
    ListNode* Node1 = new ListNode(1, nullptr, 0);
    cout << "入环节点为: " << (detectCycle(Node1) == nullptr ? -1 : detectCycle(Node1)->pos) << endl;
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}
