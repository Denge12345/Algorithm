#include <bits/stdc++.h>
using namespace std;

// 设计循环双端队列
// 测试链接 : https://leetcode.cn/problems/design-circular-deque/

class MyCircularDeque1 {
public:
    //构造函数,双端队列最大为 k 。
    MyCircularDeque1(int k) {
        limit = k;
    }
    //将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }else{
            q.push_front(value);
            return true;
        }
    }
    //将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }else{
            q.push_back(value);
            return true;
        }
    }
    //从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
    bool deleteFront() {
        if(q.empty()){
            return false;
        }else{
            q.pop_front();
            return true;
        }
    }
    //从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
    bool deleteLast() {
        if(q.empty()){
            return false;
        }else{
            q.pop_back();
            return true;
        }
    }
    //从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
    int getFront() {
        if(q.empty()){
            return -1;
        }else{
            return q.front();
        }
    }
    //获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
    int getRear() {
        if(q.empty()){
            return -1;
        }else{
            return q.back();
        }
    }
    //若双端队列为空，则返回 true ，否则返回 false  。
    bool isEmpty() {
        return q.empty();
    }
    //若双端队列满了，则返回 true ，否则返回 false 。
    bool isFull() {
        return q.size() == limit;
    }
    int limit;
    deque<int> q;
};

class MyCircularDeque2 {
public:
    //构造函数,双端队列最大为 k 。
    MyCircularDeque2(int k) {
        arr = new int[k];
        limit = k;
        l = r = size = 0;
    }
    //将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }else{
            if(isEmpty()){
                l = r = 0;
                arr[0] = value;
            }else{
                l = (l == 0 ? (limit - 1) : (l - 1));
                arr[l] = value;
            }
            size++;
            return true;
        }
    }
    //将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }else{
            if(isEmpty()){
                l = r = 0;
                arr[0] = value;
            }else{
                r = (r == (limit - 1) ? 0 : (r + 1));
                arr[r] = value;
            }            
            size++;
            return true;
        }
    }
    //从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            l = (l == (limit - 1) ? 0 : (l + 1));
            size--;
            return true;
        }
    }
    //从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else{
            r = (r == 0 ? (limit - 1) : (r - 1));
            size--;
            return true;
        }
    }
    //从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return arr[l];
        }
    }
    //获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return arr[r];
        }
    }
    //若双端队列为空，则返回 true ，否则返回 false  。
    bool isEmpty() {
        return size == 0;
    }
    //若双端队列满了，则返回 true ，否则返回 false 。
    bool isFull() {
        return size == limit;
    }
    int limit;
    int size, l, r;
    int* arr;
};

void testMyCircularDeque1(){
    cout << "===使用STL实现循环双端队列测试===" << endl;
    MyCircularDeque1 circularDeque(3); // 设置容量大小为3
    cout << circularDeque.insertLast(1) << endl;// 返回 true
    cout << circularDeque.insertLast(2) << endl;// 返回 true
    cout << circularDeque.insertFront(3) << endl;// 返回 true
    cout << circularDeque.insertFront(4) << endl;// 已经满了，返回 false
    cout << circularDeque.getRear() << endl;// 返回 2
    cout << circularDeque.isFull() << endl;	// 返回 true
    cout << circularDeque.deleteLast() << endl;// 返回 true
    cout << circularDeque.insertFront(4) << endl;// 返回 true
    cout << circularDeque.getFront() << endl;// 返回 4
}

void testMyCircularDeque2(){
    cout << "===使用数组实现循环双端队列测试===" << endl;
    MyCircularDeque2 circularDeque(3); // 设置容量大小为3
    cout << circularDeque.insertLast(1) << endl;// 返回 true
    cout << circularDeque.insertLast(2) << endl;// 返回 true
    cout << circularDeque.insertFront(3) << endl;// 返回 true
    cout << circularDeque.insertFront(4) << endl;// 已经满了，返回 false
    cout << circularDeque.getRear() << endl;// 返回 2
    cout << circularDeque.isFull() << endl;	// 返回 true
    cout << circularDeque.deleteLast() << endl;// 返回 true
    cout << circularDeque.insertFront(4) << endl;// 返回 true
    cout << circularDeque.getFront() << endl;// 返回 4
}

int main(){
    testMyCircularDeque1();
    testMyCircularDeque2();
    return 0;
}
