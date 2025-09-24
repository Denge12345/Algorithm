#include <bits/stdc++.h>
using namespace std;

// 返回无序数组中累加和为给定值的最长子数组长度
// 给定一个无序数组arr, 其中元素可正、可负、可0
// 给定一个整数aim
// 求arr所有子数组中累加和为aim的最长子数组长度
// 测试链接 : https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5

const int N = 1e5 + 9;
int a[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    int ans = 0;
    for(int i = 0, sum = 0; i < n; i++){
        sum += a[i];
        if(mp.count(sum - k)){
            ans = max(ans, i - mp[sum - k]);
        }
        if(!mp.count(sum)){
            mp[sum] = i;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
