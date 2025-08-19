#include <bits/stdc++.h>
using namespace std;

// 测试链接 : https://leetcode.cn/problems/lru-cache/
// 提交时请提交test函数之前的内容
class DoubleNode{
    public:
    int key;
    int val;
    DoubleNode* last;
    DoubleNode* next;
    DoubleNode(int k, int v) : key(k), val(v), last(nullptr), next(nullptr) {}
};

class DoubleList{
    public:
    DoubleNode* head;
    DoubleNode* tail;
    DoubleList() : head(nullptr), tail(nullptr) {}
    void addNode(DoubleNode* newNode){
        if(newNode == nullptr){
            return;
        }
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->last = tail;
            tail = newNode;
        }
    }
    void moveNodeToTail(DoubleNode* Node){
        if(tail == Node){
            return;
        }
        if(head == Node){
            head = Node->next;
            head->last = nullptr;
        }else{
            Node->last->next = Node->next;
            Node->next->last = Node->last;
        }
        Node->last = tail;
        Node->next = nullptr;
        tail->next = Node;
        tail = Node;
    }
    DoubleNode* removeHead(){
        if(head == nullptr){
            return nullptr;
        }
        DoubleNode* ans = head;
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }else{
            head = ans->next;
            head->last = nullptr;
            ans->next = nullptr;
        }
        return ans;
    }
};

class LRUCache {
public:
    unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleList* nodeList;
    int size;
    LRUCache(int capacity) {
        nodeList = new DoubleList();
        size = capacity;
    }
    int get(int key) {
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            DoubleNode* ans = keyNodeMap[key];
            nodeList->moveNodeToTail(ans);
            return ans->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            DoubleNode* node = keyNodeMap[key];
            node->val = value;
            nodeList->moveNodeToTail(node);
        }else{
            if(keyNodeMap.size() == size){
                keyNodeMap.erase(nodeList->removeHead()->key);
            }
            DoubleNode* newNode = new DoubleNode(key, value);
            keyNodeMap[key] = newNode;
            nodeList->addNode(newNode);
        }
    }
};

void test(){
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4
}

int main(){
    test();
    return 0;
}
