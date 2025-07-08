#include <bits/stdc++.h>
using namespace std;

// 用栈实现队列
// 测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/
// 直接提交这个类即可
class MyQueue {
public:
    MyQueue() {
        
    }
    //将in栈中的元素倒入到out栈中,实现先进先出
    void inToOut(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
    }
    //将元素 x 推到队列的末尾
    void push(int x) {
        in.push(x);
    }
    //从队列的开头移除并返回元素
    int pop() {
        inToOut(); //确保out栈中有元素
        int ele = out.top();
        out.pop();
        return ele;
    }
    //返回队列开头的元素
    int peek() {
        inToOut(); //确保out栈中有元素
        return out.top();
    }
    //如果队列为空，返回 true ；否则，返回 false
    bool empty() {
        return in.empty() && out.empty();
    }
    stack<int> in;
    stack<int> out;
};

// 用队列实现栈
// 测试链接 : https://leetcode.cn/problems/implement-stack-using-queues/
// 直接提交这个类即可
class MyStack {
public:
    MyStack() {
        
    }
    //将元素 x 压入栈顶
    void push(int x) {
        int n = q.size();
        q.push(x);
        //将新进入的元素作为对头,实现后进先出
        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    //移除并返回栈顶元素。
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    //返回栈顶元素。
    int top() {
        return q.front();
    }
    //如果栈是空的，返回 true ；否则，返回 false 。
    bool empty() {
        return q.empty();
    }
    queue<int> q;
};

void testMyQueue(){
    cout << "===栈实现队列===" << endl;
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl; // return false
}

void testMyStack(){
    cout << "===队列实现栈===" << endl;
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl; // 返回 2
    cout << myStack.pop() << endl; // 返回 2
    cout << myStack.empty() << endl; // 返回 False
}

int main(){
    testMyQueue();
    testMyStack();
    return 0;
}
