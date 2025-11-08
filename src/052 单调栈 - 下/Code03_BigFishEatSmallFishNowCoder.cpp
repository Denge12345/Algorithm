#include <bits/stdc++.h>
using namespace std;

// 大鱼吃小鱼问题
// 给定一个数组arr，每个值代表鱼的体重
// 每一轮每条鱼都会吃掉右边离自己最近比自己体重小的鱼，每条鱼向右找只吃一条
// 但是吃鱼这件事是同时发生的，也就是同一轮在A吃掉B的同时，A也可能被别的鱼吃掉
// 如果有多条鱼在当前轮找到的是同一条小鱼，那么在这一轮，这条小鱼同时被这些大鱼吃
// 请问多少轮后，鱼的数量就固定了
// 比如 : 8 3 1 5 6 7 2 4
// 第一轮 : 8吃3；3吃1；5、6、7吃2；4没有被吃。数组剩下 8 5 6 7 4
// 第二轮 : 8吃5；5、6、7吃4。数组剩下 8 6 7
// 第三轮 : 8吃6。数组剩下 8 7
// 第四轮 : 8吃7。数组剩下 8。
// 过程结束，返回4
// 测试链接 : https://www.nowcoder.com/practice/77199defc4b74b24b8ebf6244e1793de

const int N = 1e5 + 9;
int a[N], stk[N][2];
// stk[i][0] 表示i的体重
// stk[i][1] 表示吃掉后面的鱼需要多少轮

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int r = 0, ans = 0;
    for(int i = n - 1, curTurns; i >= 0; i--){
        // 当前轮数
        curTurns = 0;
        // 大压小
        while(r > 0 && stk[r - 1][0] < a[i]){
            curTurns = max(curTurns + 1, stk[--r][1]);
        }
        stk[r][0] = a[i];
        stk[r++][1] = curTurns;
        ans = max(ans, curTurns);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
