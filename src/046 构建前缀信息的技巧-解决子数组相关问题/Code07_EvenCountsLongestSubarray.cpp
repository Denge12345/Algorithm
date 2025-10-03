#include <bits/stdc++.h>
using namespace std;

// 每个元音包含偶数次的最长子字符串
// 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度
// 每个元音字母，即 'a'，'e'，'i'，'o'，'u'
// 在子字符串中都恰好出现了偶数次。
// 测试链接 : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mp[32];
        fill(mp, mp + 32, -2);
        mp[0] = -1;
        int ans = 0;
        for(int i = 0, status = 0, m; i < n; i++){
            m = move(s[i]);
            if(m != -1){
                status ^= 1 << m;
            }
            if(mp[status] != -2){
                ans = max(ans, i - mp[status]);
            }else{
                mp[status] = i;
            }
        }
        return ans;
    }
    int move(char cha){
        switch(cha){
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
        }
    }
};

int main(){

    return 0;
}
