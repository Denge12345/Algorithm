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

//输出单链表
void printList(ListNode* head) {
    while (head != nullptr) {
        if(head->val != -1) cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void testPartitionList(){
    
}

int main(){
    cout << "划分链表测试" << endl;
    testPartitionList();
    return 0;
}
