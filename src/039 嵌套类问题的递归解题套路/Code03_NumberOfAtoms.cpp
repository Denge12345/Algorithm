#include <bits/stdc++.h>
using namespace std;

// 含有嵌套的分子式求原子数量
// 测试链接 : https://leetcode.cn/problems/number-of-atoms/

class Solution {
public:
    string countOfAtoms(string formula) {
        where = 0;
        map<string, int> mp = f(formula, 0);
        string ans = "";
        for(auto& key : mp){
            ans += key.first;
            int cnt = key.second;
            if(cnt > 1){
                ans += to_string(cnt);
            }
        }
        return ans;
    }
    int where;
    map<string, int> f(string &s, int i){
        map<string, int> ans;
        string name = "";
        map<string, int> pre;
        int cnt = 0;
        while(i < s.size() && s[i] != ')'){
            if(s[i] >= 'A' && s[i] <='Z' || s[i] == '('){
                fill(ans, name, pre, cnt);
                name.resize(0);
                pre.clear();
                cnt = 0;
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    name += s[i++];
                }else{
                    pre = f(s, i + 1);
                    i = where + 1;
                }
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                name += s[i++];
            }else{
                cnt = cnt * 10 + s[i++] - '0';
            }
        }
        fill(ans, name, pre, cnt);
        where = i;
        return ans;
    }
    void fill(map<string, int>& ans, string& name, map<string, int>& pre, int cnt){
        if(!name.empty() || !pre.empty()){
            cnt = cnt == 0 ? 1 : cnt;
            if(name.size() > 0){
                ans[name] += cnt;
            }else{
                for(auto& key : pre){
                    ans[key.first] += pre[key.first] * cnt;
                }
            }
        }
    }
};

int main(){

    return 0;
}
