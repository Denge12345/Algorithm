#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 二维差分模版(牛客)
// 测试链接 : https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc

const int N = 1005;
ll diff[N][N];
int n, m, q;

void add(int x1, int y1, int x2, int y2, int d){
    diff[x1][y1] += d;
    diff[x2 + 1][y1] -= d;
    diff[x1][y2 + 1] -= d;
    diff[x2 + 1][y2 + 1] += d;
}

void build(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
}

void clear(){
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++){
            diff[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int val;
            cin >> val;
            add(i, j, i, j, val);
        }
    }
    while(q--){
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        add(x1, y1, x2, y2, k);
    }
    build();
    for(int i = 1; i <= n; i++){
        cout << diff[i][1];
        for(int j = 2; j <= m; j++){
            cout << " "<< diff[i][j];
        }
        cout << endl;
    }
    clear();
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
