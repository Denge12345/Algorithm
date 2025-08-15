#include <bits/stdc++.h>
using namespace std;

// 排序链表
// 要求时间复杂度O(n*logn)，额外空间复杂度O(1)，还要求稳定性
// 数组排序做不到，链表排序可以
// 测试链接 : https://leetcode.cn/problems/sort-list/

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

ListNode* findEnd(ListNode* s, int k){
    while(s->next != nullptr && --k != 0){
        s = s->next;
    }
    return s;
}

ListNode* mergeStart; //整体的头
ListNode* mergeEnd; //整体的尾

void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2){
    ListNode* pre;
    //单独处理第一个节点
    if(l1->val <= l2->val){
        mergeStart = l1;
        pre = l1;
        l1 = l1->next;
    }else{
        mergeStart = l2;
        pre = l2;
        l2 = l2->next;
    }
    //处理后续节点
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val <= l2->val){
            pre->next = l1;
            pre = l1;
            l1 = l1->next;
        }else{
            pre->next = l2;
            pre = l2;
            l2 = l2->next;
        }
    }
    //哪段没连完连哪段
    if(l1 != nullptr){
        pre->next = l1;
        mergeEnd = r1;
    }else{
        pre->next = l2;
        mergeEnd = r2;
    }
}

ListNode* sortList(ListNode* head) {
    int n = 0;
    ListNode* cur = head;
    while(cur != nullptr){
        n++;
        cur = cur->next;
    }
    ListNode* l1;
    ListNode* r1;
    ListNode* l2;
    ListNode* r2;
    ListNode* next; //表示下一段的开头
    ListNode* lastTeamEnd; //表示前一段的结尾
    for(int step = 1; step < n; step <<= 1){
        //单独处理第一段
        l1 = head;
        r1 = findEnd(l1, step);
        l2 = r1->next;
        r2 = findEnd(l2, step);
        next = r2->next;
        r1->next = nullptr;
        r2->next = nullptr;
        merge(l1, r1, l2, r2);
        head = mergeStart;
        lastTeamEnd = mergeEnd;
        //处理后续段
        while(next != nullptr){
            l1 = next;
            r1 = findEnd(l1, step);
            l2 = r1->next;
            //如果只有一段,直接连接
            if(l2 == nullptr){
                lastTeamEnd->next = l1;
                break;
            }
            r2 = findEnd(l2, step);
            next = r2->next;
            r1->next = nullptr;
            r2->next = nullptr;
            merge(l1, r1, l2, r2);
            //前一组的尾部接到当前组的头部
            lastTeamEnd->next = mergeStart;
            lastTeamEnd = mergeEnd;
        }
    }
    return head;
}

void test01(){
    ListNode* Node4 = new ListNode(3, nullptr);
    ListNode* Node3 = new ListNode(1, Node4);
    ListNode* Node2 = new ListNode(2, Node3);
    ListNode* Node1 = new ListNode(4, Node2);
    cout << "排序前: ";
    printList(Node1);
    cout << "排序后: ";
    printList(sortList(Node1));
}

void test02(){
    ListNode* Node5 = new ListNode(0, nullptr);
    ListNode* Node4 = new ListNode(4, Node5);
    ListNode* Node3 = new ListNode(3, Node4);
    ListNode* Node2 = new ListNode(5, Node3);
    ListNode* Node1 = new ListNode(-1, Node2);
    cout << "排序前: ";
    printList(Node1);
    cout << "排序后: ";
    printList(sortList(Node1));
}

int main(){
    test01();
    test02();
    return 0;
}
