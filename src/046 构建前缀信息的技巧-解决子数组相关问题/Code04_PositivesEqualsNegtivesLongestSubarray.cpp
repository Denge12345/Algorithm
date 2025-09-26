#include <bits/stdc++.h>
using namespace std;

// 返回无序数组中正数和负数个数相等的最长子数组长度
// 给定一个无序数组arr，其中元素可正、可负、可0
// 求arr所有子数组中正数与负数个数相等的最长子数组的长度
// 测试链接 : https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb

const int N = 1e5 + 9;
int a[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a[i] = (num != 0 ? (num > 0 ? 1 : -1) : 0);
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    int ans = 0;
    for(int i = 0, sum; i < n; i++){
        sum += a[i];
        if(mp.count(sum)){
            ans = max(ans, i - mp[sum]);
        }else{
            mp[sum] = i;
        }
    }
    cout << ans << endl;
}

int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
