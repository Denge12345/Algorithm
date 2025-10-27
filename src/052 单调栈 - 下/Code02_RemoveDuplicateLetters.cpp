#include <bits/stdc++.h>
using namespace std;

// 去除重复字母保证剩余字符串的字典序最小
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
// 需保证 返回结果的字典序最小
// 要求不能打乱其他字符的相对位置
// 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size(), r = 0;
        vector<int> cnts(26), stk(26);
        vector<bool> enter(26); // 字母是否在栈中
        for(char cha : s){
            cnts[cha - 'a']++;
        }
        for(char cur : s){
            // 如果cur没在栈中
            if(!enter[cur - 'a']){
                // 栈中有元素,大压小,栈顶字母有剩余 弹出
                while(r > 0 && stk[r - 1] > cur && cnts[stk[r - 1] - 'a'] > 0){
                    enter[stk[r - 1] - 'a'] = false;
                    r--;
                }
                stk[r++] = cur;
                enter[cur - 'a'] = true;
            }
            cnts[cur - 'a']--;
        }
        string ans = "";
        for(int i = 0; i < r; i++){
            ans += stk[i];
        }
        return ans;
    }
};

int main(){

    return 0;
}
