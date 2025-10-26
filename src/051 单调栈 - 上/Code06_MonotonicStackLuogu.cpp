#include <bits/stdc++.h>
using namespace std;

// 课上没讲的代码，单调栈在洛谷上的测试，原理是一样的
// 洛谷上这道题对java特别不友好，不这么写通过不了，注意看注释，非常极限
// 建议看看就好，现在的笔试和比赛时，不会这么极限的
// 给定一个长度为n的数组，打印每个位置的右侧，大于该位置数字的最近位置
// 测试链接 : https://www.luogu.com.cn/problem/P5788

const int N = 3e6 + 9;
int a[N], ans[N], stk[N];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int r = 0;
    for(int i = 1; i <= n; i++){
        while(r > 0 && a[stk[r - 1]] < a[i]){
            ans[stk[--r]] = i;
        }
        stk[r++] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
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
