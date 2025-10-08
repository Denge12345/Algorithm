#include <bits/stdc++.h>
using namespace std;

// 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 测试链接 : https://leetcode.cn/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int cnts[256];
        fill(cnts, cnts + 256, 0);
        for(char cha : t){
            cnts[cha]--;
        }
        int len = INT_MAX;
        int start = 0;
        int debt = t.size();
        for(int l = 0, r = 0; r < s.size(); r++){
            if(cnts[s[r]]++ < 0){
                debt--;
            }
            if(debt == 0){
                while(cnts[s[l]] > 0){
                    cnts[s[l++]]--;
                }
                if(r - l + 1 < len){
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main(){

    return 0;
}
