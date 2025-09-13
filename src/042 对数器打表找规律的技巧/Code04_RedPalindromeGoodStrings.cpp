#include <bits/stdc++.h>
using namespace std;

// 可以用r、e、d三种字符拼接字符串，如果拼出来的字符串中
// 有且仅有1个长度>=2的回文子串，那么这个字符串定义为"好串"
// 返回长度为n的所有可能的字符串中，好串有多少个
// 结果对 1000000007 取模， 1 <= n <= 10^9
// 示例：
// n = 1, 输出0
// n = 2, 输出3
// n = 3, 输出18

bool is(vector<char>& path, int l, int r){
    while(l < r){
        if(path[l] != path[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int f(vector<char>& path, int i){
    if(i == path.size()){
        int cnt = 0;
        for(int l = 0; l < path.size(); l++){
            for(int r = l + 1; r < path.size(); r++){
                if(is(path, l, r)){
                    cnt++;
                }
                if(cnt > 1){
                    return 0;
                }
            }
        }
        return cnt == 1 ? 1 : 0;
    }else{
        int ans = 0;
        path[i] = 'r';
        ans += f(path, i + 1);
        path[i] = 'e';
        ans += f(path, i + 1);
        path[i] = 'd';
        ans += f(path, i + 1);
        return ans;
    }
}

int num1(int n){
    vector<char> path(n);
    return f(path, 0);
}

int num2(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 3;
    }
    if(n == 3){
        return 18;
    }
    return (int) ((1ll * 6 * (n + 1)) % 1000000007);
}

int main(){
    for(int i = 1; i <= 10; i++){
        cout << "长度为: " << i << ", 答案: " << num1(i) << endl;
    }
    return 0;
}
