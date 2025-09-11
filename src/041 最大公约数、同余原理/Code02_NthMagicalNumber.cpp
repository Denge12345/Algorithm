#include <bits/stdc++.h>
using namespace std;

// 一个正整数如果能被 a 或 b 整除，那么它是神奇的。
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。
// 因为答案可能很大，所以返回答案 对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/nth-magical-number/

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long _lcm = lcm(a, b);
        long long ans = 0;
        for(long long l = 0, r = 1ll * n * min(a, b), mid = 0; l <= r;){
            mid = (l + r) / 2;
            if(mid / a + mid / b - mid / _lcm >= n){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return (int)(ans % 1000000007);
    }
    long long gcd(long long a, long long b){
        return b == 0 ? a : gcd(b, a % b);
    }
    long long lcm(long long a, long long b){
        return a / gcd(a, b) * b;
    }
};

int main(){

    return 0;
}
