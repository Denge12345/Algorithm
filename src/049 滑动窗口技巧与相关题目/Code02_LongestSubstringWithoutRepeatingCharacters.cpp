#include <bits/stdc++.h>
using namespace std;

// 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 测试链接 : https://leetcode.cn/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int last[256];
        fill(last, last + 256, -1);
        int ans = 0;
        for(int l = 0, r = 0; r < n; r++){
            l = max(l, last[s[r]] + 1);
            ans = max(ans, r - l + 1);
            last[s[r]] = r;
        }
        return ans;
    }
};

int main(){

    return 0;
}
