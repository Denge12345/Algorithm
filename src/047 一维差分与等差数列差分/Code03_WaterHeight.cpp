#include <bits/stdc++.h>
using namespace std;

// 一群人落水后求每个位置的水位高度
// 问题描述比较复杂，见测试链接
// 测试链接 : https://www.luogu.com.cn/problem/P5026

const int N = 1e6 + 9;
const int OFFSET = 30001;
int a[OFFSET + N + OFFSET];

void build(){
    for(int i = 1; i <= m + OFFSET; i++){
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= m + OFFSET; i++){
        a[i] += a[i - 1];
    }
}

void insert(int l, int r, int s, int e, int d){
    a[l + OFFSET] += s;
    a[l + OFFSET + 1] += d - s;
    a[r + OFFSET + 1] -= e + d;
    a[r + OFFSET + 2] += e;
}

void fall(int v, int x){
    insert(x - 3 * v + 1, x - 2 * v, 1, v, 1);
    insert(x - 2 * v + 1, x, v - 1, -v, -1);
    insert(x + 1, x + 2 * v, -v + 1, v, 1);
    insert(x + 2 * v + 1, x + 3 * v - 1, v - 1, 1, -1);
}

void solve(){
    int n, m;
    cin >> n >> m;
    while(n--){
        int v, x;
        cin >> v >> x;
        fall(v, x);
    }
    build();
    for(int i = 1 + OFFSET; i <= m + OFFSET; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
