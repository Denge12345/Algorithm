#include <bits/stdc++.h>
using namespace std;

//栈底元素移除掉,上面的元素盖下来
//返回移除的栈底元素
int bottomOut(stack<int>& stk){
    int ans = stk.top();
    stk.pop();
    if(stk.empty()){
        return ans;
    }else{
        int last = bottomOut(stk);
        stk.push(ans);
        return last;
    }
}

//用递归函数逆序栈
void rev(stack<int>& stk){
    if(stk.empty()){
        return;
    }
    int num = bottomOut(stk);
    rev(stk);
    stk.push(num);
}

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    rev(stk);
    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }
    return 0;
}
