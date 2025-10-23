#include <bits/stdc++.h>
using namespace std;

// 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
// 给定一个可能含有重复值的数组 arr
// 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
// 返回所有位置相应的信息。
// 输入描述：
// 第一行输入一个数字 n，表示数组 arr 的长度。
// 以下一行输入 n 个数字，表示数组的值
// 输出描述：
// 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
// 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb

const int N = 1e6 + 9;
int a[N], stk[N], n, r, ans[N][2];

void solve(){
    r = 0;
    int cur;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        while(r > 0 && a[stk[r - 1]] >= a[i]){
            cur = stk[--r];
            ans[cur][0] = r > 0 ? stk[r - 1] : -1;
            ans[cur][1] = i;
        }
        stk[r++] = i;
    }
    while(r > 0){
        cur = stk[--r];
        ans[cur][0] = r > 0 ? stk[r - 1] : -1;
        ans[cur][1] = -1;
    }
    for(int i = n - 2; i >= 0; i--){
        if(ans[i][1] != -1 && a[ans[i][1]] == a[i]){
            ans[i][1] = ans[ans[i][1]][1];
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
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
