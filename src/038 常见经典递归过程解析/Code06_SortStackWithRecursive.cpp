#include <bits/stdc++.h>
using namespace std;

// 用递归函数排序栈
// 栈只提供push、pop、isEmpty三个方法
// 请完成无序栈的排序，要求排完序之后，从栈顶到栈底从小到大
// 只能使用栈提供的push、pop、isEmpty三个方法、以及递归函数
// 除此之外不能使用任何的容器，数组也不行
// 就是排序过程中只能用：
// 1) 栈提供的push、pop、isEmpty三个方法
// 2) 递归函数，并且返回值最多为单个整数

int getDeep(stack<int>& stk){
    if(stk.empty()){
        return 0;
    }
    int num = stk.top();
    stk.pop();
    int depth = getDeep(stk) + 1;
    stk.push(num);
    return depth;
}

int getMax(stack<int>& stk, int deep){
    if(deep == 0){
        return INT_MIN;
    }
    int num = stk.top();
    stk.pop();
    int Max = max(num, getMax(stk, deep - 1));
    stk.push(num);
    return Max;
}

int getTimes(stack<int>& stk, int deep, int Max){
    if(deep == 0){
        return 0;
    }
    int num = stk.top();
    stk.pop();
    int times = getTimes(stk, deep - 1, Max) + (num == Max ? 1 : 0);
    stk.push(num);
    return times;
}

void down(stack<int>& stk, int deep, int Max, int k){
    if(deep == 0){
        for(int i = 0; i < k; i++){
            stk.push(Max);
        }
        return;
    }
    int num = stk.top();
    stk.pop();
    down(stk, deep - 1, Max, k);
    if(num != Max){
        stk.push(num);
    }
}

void sortStack(stack<int>& stk){
    int deep = getDeep(stk);
    while(deep > 0){
        int Max = getMax(stk, deep);
        int times = getTimes(stk, deep, Max);
        down(stk, deep, Max, times);
        deep -= times;
    }
}

stack<int> randomStack(int n, int v){
    stack<int> ans;
    for(int i = 0; i < n; i++){
        ans.push(rand() % v + 1);
    }
    return ans;
}

bool isSorted(stack<int>& stk){
    int step = INT_MIN;
    while(!stk.empty()){
        if(step > stk.top()){
            return false;
        }
        step = stk.top();
        stk.pop();
    }
    return true;
}

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(5);
    stk.push(4);
    stk.push(5);
    stk.push(3);
    stk.push(2);
    stk.push(3);
    stk.push(1);
    stk.push(4);
    stk.push(2);
    sortStack(stk);
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    //随机测试
    int N = 20;
    int V = 20;
    int testTimes = 20000;
    cout << "测试开始" << endl;
    for(int i = 0; i < testTimes; i++){
        int n = rand() % N + 1;
        stack<int> stk1 = randomStack(n, V);
        sortStack(stk1);
        if(!isSorted(stk1)){
            cout << "出错了" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
