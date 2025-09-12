#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Random(){
    return 1ll * rand() % LONG_MAX;
}

// 计算 ((a + b) * (c - d) + (a * c - b * d)) % mod 的非负结果
int f1(ll a, ll b, ll c, ll d, int mod){
    //Java中使用BigInteger,C++中使用__int128
    __int128 o1 = a;
    __int128 o2 = b;
    __int128 o3 = c;
    __int128 o4 = d;
    __int128 o5 = o1 + o2; // a + b
    __int128 o6 = o3 - o4; // c - d
    __int128 o7 = o1 * o3; // a * c
    __int128 o8 = o2 * o4; // b * d
    __int128 o9 = o5 * o6; // (a + b) * (c - d)
    __int128 o10 = o7 - o8; // (a * c - b * d)
    __int128 o11 = o9 + o10;
    __int128 mod128 = mod;
    __int128 result = o11 % mod128;
    if (result < 0) {
        result += mod128; // 处理负数的模运算
    }
    return static_cast<int>(result);
}

// 计算 ((a + b) * (c - d) + (a * c - b * d)) % mod 的非负结果
int f2(ll a, ll b, ll c, ll d, int mod){
    int o1 = (int)(a % mod); // a
    int o2 = (int)(b % mod); // b
    int o3 = (int)(c % mod); // c
    int o4 = (int)(d % mod); // d
    int o5 = (o1 + o2) % mod; // a + b
    int o6 = (o3 - o4 + mod) % mod; // c - d
    int o7 = (int)((1ll * o1 * o3) % mod); // a * c
    int o8 = (int)((1ll * o2 * o4) % mod); // b * d
    int o9 = (int)((1ll * o5 * o6) % mod); // (a + b) * (c - d)
    int o10 = (o7 - o8 + mod) % mod; // (a * c - b * d)
    int ans = (o9 + o10) % mod; // ((a + b) * (c - d) + (a * c - b * d)) % mod
    return ans;
}

int main(){
    srand((unsigned int)time(NULL));
    cout << "测试开始" << endl;
    int testTimes = 100000;
    int mod = 1000000007;
    for(int i = 0; i < testTimes; i++){
        ll a = Random();
        ll b = Random();
        ll c = Random();
        ll d = Random();
        if(f1(a, b, c, d, mod) != f2(a, b, c, d, mod)){
            cout << "出错了" << endl;
        }
    }
    cout << "测试结束" << endl;
    cout << "===" << endl;
    ll a = Random();
    ll b = Random();
    ll c = Random();
    ll d = Random();
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << "c : " << c << endl;
    cout << "d : " << d << endl;
    cout << "===" << endl;
    cout << "f1 : " << f1(a, b, c, d, mod) << endl;
    cout << "f2 : " << f2(a, b, c, d, mod) << endl;
    return 0;
}
