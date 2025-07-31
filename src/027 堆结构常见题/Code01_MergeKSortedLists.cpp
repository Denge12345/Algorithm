#include <bits/stdc++.h>
using namespace std;

// 合并K个有序链表
// 测试链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 直接提交如下方法即可
class Solution {
public:
    struct comp{
        bool operator()(const ListNode* u, const ListNode* v) const {
            return u->val > v->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> heap;
        for(ListNode* h : lists){
            if(h != nullptr){
                heap.push(h);
            }
        }
        if(heap.empty()){
            return nullptr;
        }
        ListNode* head = heap.top();
        ListNode* pre = head;
        heap.pop();
        if(pre->next != nullptr){
            heap.push(pre->next);
        }
        while(!heap.empty()){
            ListNode* cur = heap.top();
            heap.pop();
            pre->next = cur;
            pre = pre->next;
            if(cur->next != nullptr){
                heap.push(cur->next);
            }
        }
        pre->next = nullptr;
        return head;
    }
};

//输出单链表
void printList(ListNode* head) {
    while (head != nullptr) {
        if(head->val != -1) cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void test1(){
    cout << "=====测试样例1=====" << endl;
    ListNode* Node7 = new ListNode(7, nullptr);
    ListNode* Node6 = new ListNode(6, Node7);
    ListNode* Node5 = new ListNode(5, Node6);
    ListNode* Node4 = new ListNode(4, Node5);
    ListNode* Node3 = new ListNode(3, nullptr);
    ListNode* Node2 = new ListNode(2, Node3);
    ListNode* Node1 = new ListNode(1, Node2);
    vector<ListNode*> lists = {Node1, Node4};
    Solution solution;
    cout << "合并前: " << endl;
    for(ListNode* node : lists){
        printList(node);
    }
    cout << "合并后: " << endl;
    printList(solution.mergeKLists(lists));
}

void test2(){
    cout << "=====测试样例2=====" << endl;
    ListNode* Node6 = new ListNode(6, nullptr);
    ListNode* Node5 = new ListNode(5, nullptr);
    ListNode* Node4 = new ListNode(4, Node5);
    ListNode* Node3 = new ListNode(1, Node4);
    ListNode* Node2 = new ListNode(2, nullptr);
    ListNode* Node1 = new ListNode(1, Node2);
    vector<ListNode*> lists = {Node1, Node3, Node6};
    Solution solution;
    cout << "合并前: " << endl;
    for(ListNode* node : lists){
        printList(node);
    }
    cout << "合并后: " << endl;
    printList(solution.mergeKLists(lists));
}

int main(){
    test1();
    test2();
    return 0;
}
