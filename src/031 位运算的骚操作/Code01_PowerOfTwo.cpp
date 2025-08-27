#include <bits/stdc++.h>
using namespace std;

// Brian Kernighan算法
// 提取出二进制里最右侧的1
// 判断一个整数是不是2的幂
// 测试链接 : https://leetcode.cn/problems/power-of-two/

class Solution{
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n & -n);
    }
}

int main(){
    int n1 = 1, n2 = 16, n3 = 3;
    Solution solution;
    cout << solution.isPowerOfTwo(n1) << endl;
    cout << solution.isPowerOfTwo(n2) << endl;
    cout << solution.isPowerOfTwo(n3) << endl;
    return 0;
}
