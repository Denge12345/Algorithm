#include <bits/stdc++.h>
using namespace std;

// 二维差分模版(洛谷)
// 测试链接 : https://www.luogu.com.cn/problem/P3397

const int N = 1005;
int diff[N][N], n, q;

void add(int x1, int y1, int x2, int y2, int d){
    diff[x1][y1] += d;
    diff[x2 + 1][y1] -= d;
    diff[x1][y2 + 1] -= d;
    diff[x2 + 1][y2 + 1] += d;
}

void build(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
}

void clear(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            diff[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        add(x1, y1, x2, y2, 1);
    }
    build();
    for(int i = 1; i <= n; i++){
        cout << diff[i][1];
        for(int j = 2; j <= n; j++){
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
