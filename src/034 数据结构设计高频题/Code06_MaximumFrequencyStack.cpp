#include <bits/stdc++.h>
using namespace std;

// 最大频率栈
// 测试链接 : https://leetcode.cn/problems/maximum-frequency-stack/

class FreqStack {
public:
    //出现的最大次数
    int topTimes;
    //每层节点
    unordered_map<int, vector<int>> cntValues;
    //每一个数出现了几次
    unordered_map<int, int> valueTimes;
    FreqStack() {
        topTimes = 0;
    }
    void push(int val) {
        //val出现的次数
        valueTimes[val] = valueTimes.count(val) ? valueTimes[val] + 1 : 1;
        int curTopTimes = valueTimes[val];
        //如果找不到则创建vector
        if(cntValues.find(curTopTimes) == cntValues.end()){
            cntValues[curTopTimes] = vector<int>();
        }
        cntValues[curTopTimes].push_back(val);
        //更新
        topTimes = max(topTimes, curTopTimes);
    }
    int pop() {
        //最大出现次数的vector
        vector<int>& topTimeValue = cntValues[topTimes];
        //ans为最后一个元素
        int ans = topTimeValue.back();
        topTimeValue.pop_back();
        //如果是最后一个元素,删除vector,减少topTimes
        if(topTimeValue.size() == 0){
            cntValues.erase(topTimes--);
        }
        int times = valueTimes[ans];
        //ans出现的次数为1,则删除,否则次数-1
        if(times == 1){
            valueTimes.erase(ans);
        }else{
            valueTimes[ans] = times - 1;
        }
        return ans;
    }
};

void test(){
    FreqStack* freqStack = new FreqStack();
    freqStack->push(5);//堆栈为 [5]
    freqStack->push(7);//堆栈是 [5,7]
    freqStack->push(5);//堆栈是 [5,7,5]
    freqStack->push(7);//堆栈是 [5,7,5,7]
    freqStack->push(4);//堆栈是 [5,7,5,7,4]
    freqStack->push(5);//堆栈是 [5,7,5,7,4,5]
    cout << freqStack->pop() << endl;//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
    cout << freqStack->pop() << endl;//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
    cout << freqStack->pop() << endl;//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
    cout << freqStack->pop() << endl;//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。
}

int main(){
    test();
    return 0;
}
