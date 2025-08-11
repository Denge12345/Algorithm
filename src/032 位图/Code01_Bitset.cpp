#include <bits/stdc++.h>
using namespace std;

// 位图的实现
// Bitset(int size)
// void add(int num)
// void remove(int num)
// void reverse(int num)
// bool contains(int num)

class Bitset{
    public:
    Bitset(int size){
        //将数组中所有数据初始化为0
        st = new int[(size + 31) / 32]();
    }
    void add(int num){
        st[num / 32] |= 1 << (num % 32);
    }
    void remove(int num){
        st[num / 32] &= ~(1 << (num % 32));
    }
    void reverse(int num){
        st[num / 32] ^= 1 << (num % 32);
    }
    bool contains(int num){
        return ((st[num / 32] >> (num % 32)) & 1) == 1;
    }
    int* st;
};

int main(){
    srand((unsigned int)time(NULL));
    int n = 1000;
    int testTimes = 10000;
    cout << "测试开始" << endl;
    Bitset bitset(n);
    unordered_set<int> st;
    cout << "调用阶段开始" << endl;
    for(int i = 0; i < testTimes; i++){
        int op = rand() % 3 + 1;
        int number = rand() % n;
        if(op == 1){
            bitset.add(number);
            st.insert(number);
        }else if(op == 2){
            bitset.remove(number);
            st.erase(number);
        }else{
            bitset.reverse(number);
            if(st.count(number)){
                st.erase(number);
            }else{
                st.insert(number);
            }
        }
    }
    cout << "调用阶段结束" << endl;
    cout << "验证阶段开始" << endl;
    for(int i = 0; i < n; i++){
        if(bitset.contains(i) != (st.find(i) != st.end())){
            cout << "出错了" << endl;
            cout << i << " 在Bitset中的情况: " << bitset.contains(i) << endl;
            cout << i << " 在set中的情况: " << (st.find(i) != st.end()) << endl;
            cout << endl;
        }
    }
    cout << "验证阶段结束" << endl;
    cout << "测试结束" << endl;
    return 0;
}
