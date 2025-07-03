#include <bits/stdc++.h>
using namespace std;

// 反转单链表测试链接 : https://leetcode.cn/problems/reverse-linked-list/

//单链表节点
class ListNode{
    public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
    int val;
    ListNode* next;
};

//双链表节点
class DoubleListNode{
    public:
    DoubleListNode() : val(0), last(nullptr), next(nullptr) {}
    DoubleListNode(int val) : val(val), last(nullptr), next(nullptr) {}
    DoubleListNode(int val, DoubleListNode* last, DoubleListNode* next) : val(val), last(last), next(next) {}
    int val;
    DoubleListNode* last;
    DoubleListNode* next;
};

//反转单链表
//直接提交这个函数(或其中的内容)即可
ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr; //记录前一个节点(作为头节点)
    ListNode* next = nullptr; //临时保存后续节点
    while(head != nullptr){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

//反转双链表
//没有找到测试链接 
DoubleListNode* reverseDoubleList(DoubleListNode* head) {
    DoubleListNode* pre = nullptr;
    DoubleListNode* next = nullptr;
    while(head != nullptr){
        next = head->next;
        head->next = pre;
	//双链表要将当前节点的前指针指向下一个节点
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}

//输出单链表
void printList(ListNode* head) {
    while (head != nullptr) {
        if(head->val != -1) cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//反转单链表测试
int testReverseList(){
    //链表 1 -> 2 -> 3
    ListNode* Node3 = new ListNode(3);
    ListNode* Node2 = new ListNode(2, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    ListNode* Head = new ListNode(-1, Node1);
    cout << "原链表: ";
    printList(Head);
    cout << "反转后: ";
    printList(reverseList(Head));
}

int main(){
    //调用函数时,在函数中修改数值 
    //按值传递不会修改原函数中原来的数值
	//按引用或地址传递原函数中可以修改原来的数值
    cout << "反转单链表测试" << endl;
    testReverseList();
    return 0;
}
