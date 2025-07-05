#include <bits/stdc++.h>
using namespace std;

// 将两个升序链表合并为一个新的 升序 链表并返回
// 新链表是通过拼接给定的两个链表的所有节点组成的
// 测试链接 : https://leetcode.cn/problems/merge-two-sorted-lists/

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
        if(head->val != -1) cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//合并两个有序链表
//直接提交这个函数(或其中的内容)即可
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1 == nullptr || list2 == nullptr){
        return list1 != nullptr ? list1 : list2;
    }
    ListNode* head = list1->val <= list2->val ? list1 : list2;
    ListNode* pre = head;
    ListNode* cur1 = pre->next;
    ListNode* cur2 = pre == list1 ? list2 : list1;
    while(cur1 != nullptr && cur2 != nullptr){
        if(cur1->val <= cur2->val){
            pre->next = cur1;
            cur1 = cur1->next;
        }else{
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }
    pre->next = cur1 != nullptr ? cur1 : cur2;
    return head;
}

void testMergeTwoLists(){
    //链表1 1 -> 2 -> 4
    ListNode* List1Node3 = new ListNode(4, nullptr);
    ListNode* List1Node2 = new ListNode(2, List1Node3);
    ListNode* List1Node1 = new ListNode(1, List1Node2);
    ListNode* List1Head = new ListNode(-1, List1Node1);
    //链表2 1 -> 3 -> 4
    ListNode* List2Node3 = new ListNode(4, nullptr);
    ListNode* List2Node2 = new ListNode(3, List2Node3);
    ListNode* List2Node1 = new ListNode(1, List2Node2);
    ListNode* List2Head = new ListNode(-1, List2Node1);
    cout << "合并前:" << '\n' << "List1: ";
    printList(List1Head);
    cout << "List2: ";
    printList(List2Head);
    cout << "合并后: " << '\n' << "List: ";
    printList(mergeTwoLists(List1Head, List2Head));
}

int main(){
    cout << "合并两个链表测试" << endl;
    testMergeTwoLists();
    return 0;
}
