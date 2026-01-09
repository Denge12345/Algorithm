#include <bits/stdc++.h>
using namespace std;

// 接取落水的最小花盆
// 老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x 轴的位置
// 每滴水以每秒1个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置
// 使得从被花盆接着的第 1 滴水开始，到被花盆接着的最后 1 滴水结束，之间的时间差至少为 D
// 我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住
// 给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W
// 测试链接 : https://www.luogu.com.cn/problem/P2698

const int N = 1e5 + 9;
pair<int, int> arr[N];
int maxDeque[N], minDeque[N];
int maxh, maxt, minh, mint, n, d;

// 最大值 - 最小值 >= d
bool ok(){
    int Max = maxh < maxt ? arr[maxDeque[maxh]].second : 0;
    int Min = minh < mint ? arr[minDeque[minh]].second : 0;
    return Max - Min >= d;
}

void push(int r){
    while(maxh < maxt && arr[maxDeque[maxt - 1]].second <= arr[r].second){
        maxt--;
    }
    maxDeque[maxt++] = r;
    while(minh < mint && arr[minDeque[mint - 1]].second >= arr[r].second){
        mint--;
    }
    minDeque[mint++] = r;
}

void pop(int l){
    if(maxh < maxt && maxDeque[maxh] == l){
        maxh++;
    }
    if(minh < mint && minDeque[minh] == l){
        minh++;
    }
}

void solve(){
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, [](const pair<int, int>& u, const pair<int, int>& v){return u.first < v.first;});
    int ans = INT_MAX;
    for(int l = 0, r = 0; l < n; l++){
        // r 不越界且不满足题意就往右扩充
        while(!ok() && r < n){
            push(r++);
        }
        // 满足题意记录答案
        if(ok()){
            ans = min(ans, arr[r - 1].first - arr[l].first);
        }
        // 往左收缩
        pop(l);
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
