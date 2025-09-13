#include <bits/stdc++.h>
using namespace std;

// 现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能
// 每一个技能会有一个伤害，
// 同时若怪物小于等于一定的血量，则该技能可能造成双倍伤害
// 每一个技能最多只能释放一次，已知怪物有m点血量
// 现在想问你最少用几个技能能消灭掉他(血量小于等于0)
// 技能的数量是n，怪物的血量是m
// i号技能的伤害是x[i]，i号技能触发双倍伤害的血量最小值是y[i]
// 1 <= n <= 10
// 1 <= m、x[i]、y[i] <= 10^6
// 测试链接 : https://www.nowcoder.com/practice/d88ef50f8dab4850be8cd4b95514bbbd

const int N = 11;
int Kill[N], Blood[N];

int f(int n, int i, int r){
    if(r <= 0){
        return i;
    }
    if(i == n){
        return INT_MAX;
    }
    int ans = INT_MAX;
    for(int j = i; j < n; j++){
        swap(Kill[i], Kill[j]);
        swap(Blood[i], Blood[j]);
        ans = min(ans, f(n, i + 1, r - (r > Blood[i] ? Kill[i] : 2 * Kill[i])));
        swap(Kill[i], Kill[j]);
        swap(Blood[i], Blood[j]);
    }
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> Kill[i] >> Blood[i];
    }
    int ans = f(n, 0, m);
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
