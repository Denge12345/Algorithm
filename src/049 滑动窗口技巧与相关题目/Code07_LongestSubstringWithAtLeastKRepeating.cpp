#include <bits/stdc++.h>
using namespace std;

// 至少有K个重复字符的最长子串
// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串
// 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度
// 如果不存在这样的子字符串，则返回 0。
// 测试链接 : https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int cnts[256];
        int ans = 0;
        // require表示出现字符的种类
        for(int require = 1; require <= 26; require++){
            fill(cnts, cnts + 256, 0);
            // collect表示当前窗口内实际包含的字符种类数
            // satisfy表示当前窗口内满足出现次数 >= k 的字符种类数
            for(int l = 0, r = 0, collect = 0, satisfy = 0; r < n; r++){
                cnts[s[r]]++;
                if(cnts[s[r]] == 1){
                    collect++;
                }
                if(cnts[s[r]] == k){
                    satisfy++;
                }
                while(collect > require){
                    if(cnts[s[l]] == 1){
                        collect--;
                    }
                    if(cnts[s[l]] == k){
                        satisfy--;
                    }
                    cnts[s[l++]]--;
                }
                if(satisfy == require){
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}
