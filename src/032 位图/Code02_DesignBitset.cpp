#include <bits/stdc++.h>
using namespace std;

// 位图的实现
// Bitset是一种能以紧凑形式存储位的数据结构
// Bitset(int n) : 初始化n个位，所有位都是0
// void fix(int i) : 将下标i的位上的值更新为1
// void unfix(int i) : 将下标i的位上的值更新为0
// void flip() : 翻转所有位的值
// boolean all() : 是否所有位都是1
// boolean one() : 是否至少有一位是1
// int count() : 返回所有位中1的数量
// String toString() : 返回所有位的状态
// 测试链接 : https://leetcode-cn.com/problems/design-bitset/

class Bitset {
public:
    Bitset(int size) {
        st = new int[(size + 31 / 32)]();
        capacity = size;
        ones = 0;
        zeros = size;
        reverse = false;
    }
    //添加idx
    void fix(int idx) {
        int index = idx / 32;
        int bit = idx % 32;
        if(!reverse){
            //没进行反转
            //1 : 存在
            //0 : 不存在
            if((st[index] & (1 << bit)) == 0){
                ones++;
                zeros--;
                st[index] |= (1 << bit);
            }
        }else{
            //进行反转
            //1 : 不存在
            //0 : 存在
            if((st[index] & (1 << bit)) != 0){
                ones++;
                zeros--;
                st[index] ^= (1 << bit);
            }
        }
    }
    //删除idx
    void unfix(int idx) {
        int index = idx / 32;
        int bit = idx % 32;
        if(!reverse){
            if((st[index] & (1 << bit)) != 0){
                ones--;
                zeros++;
                st[index] ^= (1 << bit);
            }
        }else{
            if((st[index] & (1 << bit)) == 0){
                ones--;
                zeros++;
                st[index] |= (1 << bit);
            }
        }
    }
    void flip() {
        reverse = !reverse;
        int tmp = ones;
        ones = zeros;
        zeros = tmp;
    }
    bool all() {
        return ones == capacity;
    }
    bool one() {
        return ones > 0;
    }
    int count() {
        return ones;
    }
    string toString() {
        string ans = "";
        for(int i = 0, k = 0; i < capacity; k++){
            int number = st[k];
            for(int j = 0; j < 32 && i < capacity; i++, j++){
                int status = (number >> j) & 1;
                status ^= reverse ? 1 : 0;
                ans += (char)(status + '0');
            }
        }
        return ans;
    }
    int* st;
    int capacity;
    int ones;
    int zeros;
    bool reverse;
};

void test(){
    Bitset bs(5); // bitset = "00000".
    bs.fix(3);     // 将 idx = 3 处的值更新为 1 ，此时 bitset = "00010" 。
    bs.fix(1);     // 将 idx = 1 处的值更新为 1 ，此时 bitset = "01010" 。
    bs.flip();     // 翻转每一位上的值，此时 bitset = "10101" 。
    cout << bs.all() << endl;      // 返回 False ，bitset 中的值不全为 1 。
    bs.unfix(0);   // 将 idx = 0 处的值更新为 0 ，此时 bitset = "00101" 。
    bs.flip();     // 翻转每一位上的值，此时 bitset = "11010" 。
    cout << bs.one() << endl;      // 返回 True ，至少存在一位的值为 1 。
    bs.unfix(0);   // 将 idx = 0 处的值更新为 0 ，此时 bitset = "01010" 。
    cout << bs.count() << endl;    // 返回 2 ，当前有 2 位的值为 1 。
    cout << bs.toString() << endl; // 返回 "01010" ，即 bitset 的当前组成情况。
}

int main(){
    test();
    return 0;
}
