#include <bits/stdc++.h>
using namespace std;

// 并查集模版(牛客)
// 路径压缩 + 小挂大
// 测试链接 : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372

const int N = 1e6 + 9;
int father[N], sz[N], stk[N];

void build(int n){
    for(int i = 0; i <= n; i++){
        father[i] = i;
        sz[i] = 1;
    }
}

int find(int i){
    int size = 0;
    while(i != father[i]){
        stk[size++] = i;
        i = father[i];
    }
    while(size > 0){
        father[stk[--size]] = i;
    }
    return i;
}

bool isSameSet(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        if(sz[fx] >= sz[fy]){
            sz[fx] += sz[fy];
            father[fy] = fx;
        }else{
            sz[fy] += sz[fx];
            father[fx] = fy;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    build(n);
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            cout << (isSameSet(x, y) ? "Yes" : "No") << '\n';
        }else{
            Union(x, y);
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
