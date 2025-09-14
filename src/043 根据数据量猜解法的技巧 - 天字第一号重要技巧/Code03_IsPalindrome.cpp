#include <bits/stdc++.h>
using namespace std;

// 超级回文数中的一个小函数，本身也是一道题 : 判断一个数字是不是回文数
// 测试链接 : https://leetcode.cn/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int offset = 1;
        while(x / offset >= 10){
            offset *= 10;
        }
        while(x != 0){
            if(x / offset != x % 10){
                return false;
            }
            x = (x % offset) / 10;
            offset /= 100;
        }
        return true;
    }
};

int main(){
    Solution solution;
    cout << solution.isPalindrome(121) << endl;
    cout << solution.isPalindrome(-121) << endl;
    cout << solution.isPalindrome(10) << endl;
    return 0;
}
