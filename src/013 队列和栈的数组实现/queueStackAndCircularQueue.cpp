#include <bits/stdc++.h>
using namespace std;

//用数组手写队列
class Queue{
    public:
    void push(int x){
        arr[r++] = x;
    }
    void pop(){
        l++;
    }
    int front(){
        return arr[l];
    }
    int size(){
        return r - l;
    }
    bool empty(){
        return !(r - l);
    }
    int l = 0, r = 0;
    //入队元素最好不要超过1000
    int arr[1005] = {0};
};

//用数组手写栈
class Stack{
    public:
    void push(int x){
        arr[cur_top++] = x;
    }
    void pop(){
        if(cur_top > 0) cur_top--;
    }
    int top(){
        return arr[cur_top - 1];
    }
    int size(){
        return cur_top;
    }
    bool empty(){
        return !cur_top;
    }
    int cur_top = 0;
    //入栈元素最好不要超过1000
    int arr[1005] = {0};
};

// 设计循环队列
// 直接提交下面的类即可
// 测试链接 : https://leetcode.cn/problems/design-circular-queue/
class MyCircularQueue {
public:
    //构造器，设置队列长度为 k 。
    MyCircularQueue(int k) {
        arr = new int[k];
        l = r = size = 0;
        limit = k;
    }
    //向循环队列插入一个元素。如果成功插入则返回真。
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else{
            arr[r] = value;
            r = r == limit - 1 ? 0 : (r + 1);
            size++;
            return true;
        }
    }
    //从循环队列中删除一个元素。如果成功删除则返回真。
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else{
            l = l == limit - 1 ? 0 : (l + 1);
            size--;
            return true;
        }
    }
    //从队首获取元素。如果队列为空，返回 -1 。
    int Front() {
        if(isEmpty()){
            return -1;   
        }else{
            return arr[l];
        }
    }
    //获取队尾元素。如果队列为空，返回 -1 。
    int Rear() {
        if(isEmpty()){
            return -1;
        }else{
            int last = r == 0 ? (limit - 1) : (r - 1);
            return arr[last];
        }
    }
    //检查循环队列是否为空。
    bool isEmpty() {
        return size == 0;
    }
    //检查循环队列是否已满。
    bool isFull() {
        return size == limit;
    }
    int limit, size, l, r;
    int* arr;
};

//手写队列测试
void queueTest(){
    cout << "===手写队列测试===" << endl;
    Queue q;
    q.push(10);
    q.push(20);
    cout << "对头为: " << q.front() << endl;
    q.pop();
    cout << "对头为: " << q.front() << endl;
    q.push(30);
    cout << "对头为: " << q.front() << endl;
    cout << "队列大小为: " << q.size() << endl;
    q.pop();
    q.pop();
    cout << "队列是否为空: " << q.empty() << endl;
}

//手写栈测试
void stackTest(){
    cout << "===手写栈测试===" << endl;
    Stack stk;
    stk.push(10);
    stk.push(20);
    cout << "栈顶为: " << stk.top() << endl;
    stk.pop();
    cout << "栈顶为: " << stk.top() << endl;
    stk.push(30);
    cout << "栈顶为: " << stk.top() << endl;
    cout << "栈的大小为: " << stk.size() << endl;
    stk.pop();
    stk.pop();
    cout << "栈是否为空: " << stk.empty() << endl;
}

//C++STL中的Queue
void cppInternalQueue(){
    /*
    q.push() 入队
    q.pop() 出队
    q.front() 获取对头
    q.size() 队列大小
    q.empty() 是否为空
    */
   cout << "===C++STL中的Queue===" << endl;
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << "对头为: " << q.front() << endl;
    q.pop();
    cout << "对头为: " << q.front() << endl;
    q.push(30);
    cout << "对头为: " << q.front() << endl;
    cout << "队列大小为: " << q.size() << endl;
    q.pop();
    q.pop();
    cout << "队列是否为空: " << q.empty() << endl;
}

//C++STL中的Stack
void cppInternalStack(){
    /*
    stk.push() 入栈
    stk.pop() 出栈
    stk.top() 获取栈顶
    stk.size() 栈大小
    stk.empty() 是否为空
    */
    cout << "===C++STL中的Stack===" << endl;
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    cout << "栈顶为: " << stk.top() << endl;
    stk.pop();
    cout << "栈顶为: " << stk.top() << endl;
    stk.push(30);
    cout << "栈顶为: " << stk.top() << endl;
    cout << "栈的大小为: " << stk.size() << endl;
    stk.pop();
    stk.pop();
    cout << "栈是否为空: " << stk.empty() << endl;
}

//循环队列测试
void circularQueueTest(){
    cout << "===循环队列测试===" << endl;
    MyCircularQueue circularQueue(3); // 设置长度为 3
    cout << circularQueue.enQueue(1) << endl;  // 返回 true
    cout << circularQueue.enQueue(2) << endl;  // 返回 true
    cout << circularQueue.enQueue(3) << endl;  // 返回 true
    cout << circularQueue.enQueue(4) << endl;  // 返回 false，队列已满
    cout << circularQueue.Rear() << endl;  // 返回 3
    cout << circularQueue.isFull() << endl;  // 返回 true
    cout << circularQueue.deQueue() << endl;  // 返回 true
    cout << circularQueue.enQueue(4) << endl;  // 返回 true
    cout << circularQueue.Rear() << endl;  // 返回 4
}

int main(){
    cppInternalQueue();
    cppInternalStack();
    queueTest();
    stackTest();
    circularQueueTest();
    return 0;
}
