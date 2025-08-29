#include <bits/stdc++.h>
using namespace std;

// 每k个节点一组翻转链表
// 测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/

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

class Solution {
public:
    ListNode* teamEnd(ListNode* s, int k){
        while(--k != 0 && s != nullptr){
            s = s->next;
        }
        return s;
    }
    
    void reverse(ListNode* s, ListNode* e){
        e = e->next;
        ListNode* pre = nullptr; //前一个节点
        ListNode* cur = s; //当前节点
        ListNode* next = nullptr; //下一个节点
        while(cur != e){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        s->next = e;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k){
        //第一段单独处理,因为要换头
        ListNode* start = head;
        ListNode* end = teamEnd(start, k);
        if(end == nullptr){
            return head;
        }
        head = end;
        reverse(start, end);
        //lastTeamEnd表示上一组的尾部
        ListNode* lastTeamEnd = start;
        //处理后续段
        while(lastTeamEnd->next != nullptr){
            //start和end来到下一组
            start = lastTeamEnd->next;
            end = teamEnd(start, k);
            if(end == nullptr){
                return head;
            }
            //反转后,end变为头部,start变为尾部
            reverse(start, end);
            //将上一组的尾部指向end
            lastTeamEnd->next = end;
            //上一组的尾部指向下一组的尾部
            lastTeamEnd = start;
        }
        return head;
    }
}

void test01(){
    cout << "=====测试1=====" << endl;
    ListNode* Node5 = new ListNode(5, nullptr);
    ListNode* Node4 = new ListNode(4, Node5);
    ListNode* Node3 = new ListNode(3, Node4);
    ListNode* Node2 = new ListNode(2, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    Solution solution;
    cout << "链表: ";
    printList(Node1);
    cout << "反转后的结果: ";
    printList(solution.reverseKGroup(Node1, 2));
}

void test02(){
    cout << "=====测试2=====" << endl;
    ListNode* Node5 = new ListNode(5, nullptr);
    ListNode* Node4 = new ListNode(4, Node5);
    ListNode* Node3 = new ListNode(3, Node4);
    ListNode* Node2 = new ListNode(2, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    Solution solution;
    cout << "链表: ";
    printList(Node1);
    cout << "反转后的结果: ";
    printList(solution.reverseKGroup(Node1, 3));
}

int main(){
    test01();
    test02();
    return 0;
}
