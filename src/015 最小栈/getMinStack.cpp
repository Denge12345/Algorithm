#include <bits/stdc++.h>
using namespace std;

// 最小栈
// 测试链接 : https://leetcode.cn/problems/min-stack/

// 使用STL实现
// 提交时请修改类名和构造函数名称为MinStack
class MinStack1 {
public:
    //初始化堆栈对象。
    MinStack() {
        
    }
    //将元素val推入堆栈。
    void push(int val) {
        origin.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }else{
            if(val >= minStack.top()){
                minStack.push(minStack.top());
            }else{
                minStack.push(val);
            }
        }
    }
    //删除堆栈顶部的元素。
    void pop() {
        origin.pop();
        minStack.pop();
    }
    //获取堆栈顶部的元素。
    int top() {
        return origin.top();
    }
    //获取堆栈中的最小元素。
    int getMin() {
        return minStack.top();
    }
    stack<int> origin;
    stack<int> minStack;
};

// 使用数组实现
// 提交时请修改类名和构造函数名称为MinStack
class MinStack2{
    public:
    //初始化堆栈对象。
    MinStack() {
        
    }
    //将元素val推入堆栈。
    void push(int val) {
        origin[cur_top] = val;
        if(cur_top == 0){
            minStack[cur_top] = val;
        }else{
            if(val >= minStack[cur_top - 1]){
                minStack[cur_top] = minStack[cur_top - 1];
            }else{
                minStack[cur_top] = val;
            }
        }
        cur_top++;
    }
    //删除堆栈顶部的元素。
    void pop() {
        cur_top--;
    }
    //获取堆栈顶部的元素。
    int top() {
        return origin[cur_top - 1];
    }
    //获取堆栈中的最小元素。
    int getMin() {
        return minStack[cur_top - 1];
    }
    //leetcode可能会更新测试样例
    //如果题目不能通过了,需要更改数组的大小
    int origin[8005] = {0};
    int minStack[8005] = {0};
    int cur_top = 0;
};

void testGetMinStack1(){
    cout << "===使用STL实现最小栈测试===" << endl;
    MinStack1 minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;   //--> 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;      //--> 返回 0.
    cout << minStack.getMin() << endl;   //--> 返回 -2.
}

void testGetMinStack2(){
    cout << "===使用数组实现最小栈测试===" << endl;
    MinStack2 minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;   //--> 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;      //--> 返回 0.
    cout << minStack.getMin() << endl;   //--> 返回 -2.
}

int main(){
    testGetMinStack1();
    testGetMinStack2();
    return 0;
}
