#include <bits/stdc++.h>
using namespace std;

// 判断一个整数是不是3的幂
// 测试链接 : https://leetcode.cn/problems/power-of-three/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
}

int main(){
    int n1 = 27, n2 = 0, n3 = 9, n4 = 45;
    Solution solution;
    cout << solution.isPowerOfThree(n1) << endl;
    cout << solution.isPowerOfThree(n2) << endl;
    cout << solution.isPowerOfThree(n3) << endl;
    cout << solution.isPowerOfThree(n4) << endl;
    return 0; 
}
