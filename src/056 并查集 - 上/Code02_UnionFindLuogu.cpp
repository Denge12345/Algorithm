#include <bits/stdc++.h>
using namespace std;

// 并查集模版(洛谷)
// 本实现用递归函数实现路径压缩，而且省掉了小挂大的优化，一般情况下可以省略
// 测试链接 : https://www.luogu.com.cn/problem/P3367

const int N = 2e5 + 9;
int father[N];

void build(int n){
    for(int i = 0; i <= n; i++){
        father[i] = i;
    }
}

int find(int i){
    if(i != father[i]){
        father[i] = find(father[i]);
    }
    return father[i];
}

bool isSameSet(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    father[find(x)] = find(y);
}

void solve(){
    int n, m;
    cin >> n >> m;
    build(n);
    while(m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1){
            Union(x, y);
        }else{
            cout << (isSameSet(x, y) ? "Y" : "N") << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
