#include <bits/stdc++.h>
using namespace std;

// 不用任何算术运算，只用位运算实现加减乘除
// 代码实现中你找不到任何一个算术运算符
// 测试链接 : https://leetcode.cn/problems/divide-two-integers/

const int MIN = INT_MIN;

int Add(int a, int b){
    int ans = a;
    while(b != 0){
        ans = a ^ b;
        b = (a & b) << 1;
        a = ans;
    }
    return ans;
}

int Neg(int n){
    return Add(~n, 1);
}

int Minus(int a, int b){
    return Add(a, Neg(b));
}

int Mul(int a, int b){
    int aa = a < 0 ? Neg(a) : a;
    int bb = b < 0 ? Neg(b) : b;
    int ans = 0;
    while(bb != 0){
        if((bb & 1) != 0){
            ans = Add(ans, aa);
        }
        aa <<= 1;
        bb >>= 1;
    }
    return (a > 0) ^ (b > 0) ? Neg(ans) : ans;
}

int Multiply(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    }
    if(a == MIN){
        if(b == 1){
            return MIN;
        }
        if(b == -1){
            return INT_MAX;
        }
    }
    if(b == MIN){
        if(a == 1){
            return MIN;
        }
        if(a == -1){
            return INT_MAX;
        }
    }
    Mul(a, b);
}

int Div(int a, int b){
    int x = a < 0 ? Neg(a) : a;
    int y = b < 0 ? Neg(b) : b;
    int ans = 0;
    for(int i = 30; i >= 0; i = Minus(i, 1)){
        if((x >> i) >= y){
            ans |= (1 << i);
            x = Minus(x, y);
        }
    }
    return a < 0 ^ b < 0 ? Neg(ans) : ans;
}

int Divide(int a, int b){
    if(a == MIN && b == MIN){
        return 1;
    }
    if(a != MIN && b != MIN){
        return Div(a, b);
    }
    if(b == MIN){
        return 0;
    }
    if(b == Neg(1)){
        return INT_MAX;
    }
    //a是整数最小,b不是整数最小也不是-1
    //b > 0 让 a + b -> (a / b) + 1 最后结果 -1
    //b < 0 让 a - b -> (a / b) - 1 最后结果 +1
    a = Add(a, b > 0 ? b : Neg(b));
    int ans = Div(a, b);
    int offset = b > 0 ? Neg(1) : 1;
    return Add(ans, offset);
}

int main(){
    cout << Add(12, 14) << endl;
    cout << Add(12, -14) << endl;
    cout << Minus(10, 20) << endl;
    cout << Minus(10, -20) << endl;
    cout << Mul(10, 20) << endl;
    cout << Mul(10, -20) << endl;
    cout << Div(10, 20) << endl;
    cout << Div(20, 10) << endl;
    cout << Div(20, -10) << endl;
    return 0;
}
