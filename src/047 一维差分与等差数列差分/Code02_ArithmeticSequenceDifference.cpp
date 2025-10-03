#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
// 表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
// m个操作做完之后，统计1~n范围上所有数字的最大值和异或和
// 测试链接 : https://www.luogu.com.cn/problem/P4231

const int N = 1e7 + 9;
ll arr[N];
int n, m;

void build(){
    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }
    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }
}

void sett(int l, int r, int s, int e, int d){
    arr[l] += s;
    arr[l + 1] += d - s;
    arr[r + 1] -= d + e;
    arr[r + 2] += e;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while(m--){
       int l, r, s, e;
       cin >> l >> r >> s >> e;
       sett(l, r, s, e, (e - s) / (r - l));
    }
    build();
    ll maxEle = 0;
    ll xorSum = 0;
    for(int i = 1; i <= n; i++){
        maxEle = max(maxEle, arr[i]);
        xorSum ^= arr[i];
    }
    cout << xorSum << " " << maxEle << endl;
    return 0;
}
