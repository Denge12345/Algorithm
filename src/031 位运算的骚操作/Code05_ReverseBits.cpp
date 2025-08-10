#include <bits/stdc++.h>
using namespace std;

// 逆序二进制的状态
// 测试链接 : https://leetcode.cn/problems/reverse-bits/

uint32_t reverseBits(uint32_t n) {
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = (n >> 16) | (n << 16);
    return n;
}

int main(){
    uint32_t n1 = 43261596, n2 = 4294967293;
    cout << reverseBits(n1) << endl;
    cout << reverseBits(n2) << endl;
    return 0;
}
