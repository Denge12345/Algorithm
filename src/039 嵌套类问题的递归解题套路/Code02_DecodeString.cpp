#include <bits/stdc++.h>
using namespace std;

// 含有嵌套的字符串解码
// 测试链接 : https://leetcode.cn/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        where = 0;
        return f(s, 0);
    }
    int where;
    string f(string& s, int i){
        int cnt = 0;
        string ans = "";
        while(i < s.size() && s[i] != ']'){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i++];
            }else if(s[i] >= '0' && s[i] <= '9'){
                cnt = cnt * 10 + s[i++] - '0';
            }else{
                ans += get(f(s, i + 1), cnt);
                cnt = 0;
                i = where + 1;
            }
        }
        where = i;
        return ans;
    }
    string get(string s, int cnt){
        string ans = "";
        for(int i = 0; i < cnt; i++){
            ans += s;
        }
        return ans;
    }
};

int main(){

    return 0;
}
