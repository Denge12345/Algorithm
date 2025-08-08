#include <bits/stdc++.h>
using namespace std;

// 判断一个整数是不是3的幂
// 测试链接 : https://leetcode.cn/problems/power-of-three/

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

int main(){
    int n1 = 27, n2 = 0, n3 = 9, n4 = 45;
    cout << isPowerOfThree(n1) << endl;
    cout << isPowerOfThree(n2) << endl;
    cout << isPowerOfThree(n3) << endl;
    cout << isPowerOfThree(n4) << endl;
    return 0; 
}
