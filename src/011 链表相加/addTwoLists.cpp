#include <bits/stdc++.h>
using namespace std;

// 给你两个 非空 的链表，表示两个非负的整数
// 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头
// 测试链接：https://leetcode.cn/problems/add-two-numbers/

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

//链表相加
//直接提交这个函数(或其中的内容)即可
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* cur = nullptr;
    ListNode* ans = nullptr;
    int carry, val, sum;
    while(l1 != nullptr || l2 != nullptr){
        sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
        val = sum % 10;
        carry = sum / 10;
        if(ans == nullptr){
            cur = new ListNode(val, nullptr);
            ans = cur;
        }else{
            cur->next = new ListNode(val, nullptr);
            cur = cur->next;
        }
        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
    }
    if(carry == 1){
        cur->next = new ListNode(1, nullptr);
        cur = cur->next;
    }
    return ans;
}

void testAddTwoNumbers(){
    //链表1 2 -> 4 -> 3
    ListNode* List1Node3 = new ListNode(3, nullptr);
    ListNode* List1Node2 = new ListNode(4, List1Node3);
    ListNode* List1Node1 = new ListNode(2, List1Node2);
    ListNode* List1Head = new ListNode(-1, List1Node1);
    //链表2 5 -> 6 -> 4
    ListNode* List2Node3 = new ListNode(4, nullptr);
    ListNode* List2Node2 = new ListNode(6, List2Node3);
    ListNode* List2Node1 = new ListNode(5, List2Node2);
    ListNode* List2Head = new ListNode(-1, List2Node1);
    cout << "操作前:" << '\n' << "List1: ";
    printList(List1Head);
    cout << "List2: ";
    printList(List2Head);
    cout << "操作后: " << '\n' << "List: ";
    printList(addTwoNumbers(List1Head, List2Head));
}

int main(){
    cout << "链表相加测试" << endl;
    testAddTwoNumbers();
    return 0;
}
