#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 基数排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177

const int N = 1e5 + 9;
int BASE = 10, n;
ll help[N], a[N], cnts[N];

int bits(ll num){
    int res = 0;
    while(num){
        num /= BASE;
        res++;
    }
    return res;
}

void radixSort(int bit){
    for(int offset = 1; bit > 0; offset *= BASE, bit--){
        memset(cnts, 0, sizeof(cnts));
        for(int i = 0; i < n; i++){
            cnts[(a[i] / offset) % BASE]++;
        }
        for(int i = 1; i < BASE; i++){
            cnts[i] = cnts[i] + cnts[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            help[--cnts[(a[i] / offset) % BASE]] = a[i];
        }
        for(int i = 0; i < n; i++){
            a[i] = help[i];
        }
    }
}

int main(){
    ll mina = INT_MAX, maxa = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    for(int i = 0; i < n; i++){
        a[i] -= mina;
        maxa = max(maxa, a[i]);
    }
    radixSort(bits(maxa));
    for(int i = 0; i < n; i++){
        a[i] += mina;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
