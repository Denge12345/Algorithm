#include <bits/stdc++.h>
using namespace std;

// 给你两个整数 left 和 right ，表示区间 [left, right]
// 返回此区间内所有数字 & 的结果
// 包含 left 、right 端点
// 测试链接 : https://leetcode.cn/problems/bitwise-and-of-numbers-range/

int rangeBitwiseAnd(int left, int right) {
    while(left < right){
        right -= right & -right;
    }
    return right;
}

int main(){
    int left1 = 5, right1 = 7;
    int left2 = 0, right2 = 0;
    int left3 = 0, right3 = 2147483647;
    cout << rangeBitwiseAnd(left1, right1) << endl;
    cout << rangeBitwiseAnd(left2, right2) << endl;
    cout << rangeBitwiseAnd(left3, right3) << endl;
    return 0;
}
