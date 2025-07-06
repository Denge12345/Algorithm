#include <bits/stdc++.h>
using namespace std;

// 给你一个链表的头节点 head 和一个特定值 x
// 请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置
// 测试链接 : https://leetcode.cn/problems/partition-list/

//单链表节点
class ListNode{
    public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
    int val;
    ListNode* next;
};

//划分链表
//直接提交这个函数(或其中的内容)即可
ListNode* partition(ListNode* head, int x){
    ListNode* leftHead = nullptr; // < x 的区域
	ListNode* leftTail = nullptr; 
    ListNode* rightHead = nullptr; // >= x 的区域
	ListNode* rightTail = nullptr; 
    ListNode* next = nullptr;
    while(head != nullptr){
        next = head->next;
        head->next = nullptr;
        if(head->val < x){
            if(leftHead == nullptr){
                leftHead = head;
            }else{
                leftTail->next = head;
            }
            leftTail = head;
        }else{
            if(rightHead == nullptr){
                rightHead = head;
            }else{
                rightTail->next = head;
            }
            rightTail = head;
        }
        head = next;
    }
    if(leftHead == nullptr){
        return rightHead;
    }
    // < x 的区域有内容
    leftTail->next = rightHead;
    return leftHead;
}

//划分链表
//创建新链表的方法
//直接提交这个函数(或其中的内容)即可
/*ListNode* partition(ListNode* head, int x) {
    if(head == nullptr){
        return head;
    }
    ListNode* ans1 = nullptr; // < x 的区域
    ListNode* ans2 = nullptr;
    ListNode* cur1 = nullptr; // >= x 的区域
    ListNode* cur2 = nullptr;
    int val;
    while(head != nullptr){
        val = head->val;
        if(val < x){
            if(ans1 == nullptr){
                ans1 = new ListNode(val, nullptr);
                cur1 = ans1;
            }else{
                cur1->next = new ListNode(val, nullptr);
                cur1 = cur1->next;
            }
        }else{
            if(ans2 == nullptr){
                ans2 = new ListNode(val, nullptr);
                cur2 = ans2;
            }else{
                cur2->next = new ListNode(val, nullptr);
                cur2 = cur2->next;
            }
        }
        head = head->next;
    }
    //如果都有内容就合并
    if(ans1 != nullptr && ans2 != nullptr){
        cur1->next = ans2;
    }
    //只返回有内容的区域
    return ans1 != nullptr ? ans1 : ans2;
}*/

//输出单链表
void printList(ListNode* head) {
    while (head != nullptr) {
        if(head->val != -1) cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void testPartitionList(){
    //链表 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* Node6 = new ListNode(2, nullptr);
    ListNode* Node5 = new ListNode(5, Node6);
    ListNode* Node4 = new ListNode(2, Node5);
    ListNode* Node3 = new ListNode(3, Node4);
    ListNode* Node2 = new ListNode(4, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    ListNode* Head = new ListNode(-1, Node1);
    cout << "原链表: ";
    printList(Head);
    cout << "划分后: ";
    printList(partition(Head, 3));
}

int main(){
    cout << "划分链表测试" << endl;
    testPartitionList();
    return 0;
}
