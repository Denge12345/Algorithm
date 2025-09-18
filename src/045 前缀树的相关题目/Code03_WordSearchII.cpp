#include <bits/stdc++.h>
using namespace std;

// 在二维字符数组中搜索可能的单词
// 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words
// 返回所有二维网格上的单词。单词必须按照字母顺序，通过 相邻的单元格 内的字母构成
// 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
// 同一个单元格内的字母在一个单词中不允许被重复使用
// 1 <= m, n <= 12
// 1 <= words.length <= 3 * 10^4
// 1 <= words[i].length <= 10
// 测试链接 : https://leetcode.cn/problems/word-search-ii/

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build(words);
        vector<string> ans;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, 1, ans);
            }
        }
        clear();
        return ans;
    }
    int dfs(vector<vector<char>>& board, int i, int j, int t, vector<string>& ans){
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] == 0){
            return 0;
        }
        char tmp = board[i][j];
        int road = board[i][j] - 'a';
        t = tree[t][road];
        if(pass[t] == 0){
            return 0;
        }
        int fix = 0;
        if(endd[t] != ""){
            fix++;
            ans.push_back(endd[t]);
            endd[t] = "";
        }
        board[i][j] = 0;
        fix += dfs(board, i - 1, j, t, ans);
        fix += dfs(board, i + 1, j, t, ans);
        fix += dfs(board, i, j - 1, t, ans);
        fix += dfs(board, i, j + 1, t, ans);
        pass[t] -= fix;
        board[i][j] = tmp;
        return fix;
    }
    int tree[10001][26], pass[10001], cnt;
    string endd[10001];
    void build(vector<string>& words){
        cnt = 1;
        for(int i = 0; i < words.size(); i++){
            insert(words[i]);
        }
    }
    void insert(string word){
        int cur = 1;
        pass[cur]++;
        for(int i = 0, path; i < word.size(); i++){
            path = word[i] - 'a';
            if(tree[cur][path] == 0){
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
            pass[cur]++;
        }
        endd[cur] = word;
    }
    void clear(){
        for(int i = 1; i <= cnt; i++){
            memset(tree[i], 0, sizeof(tree[i]));
            pass[i] = 0;
            endd[i] = "";
        }
    }
};

int main(){

    return 0;
}
