#include <bits/stdc++.h>
using namespace std;

// 牛牛和他的朋友们约定了一套接头密匙系统，用于确认彼此身份
// 密匙由一组数字序列表示，两个密匙被认为是一致的，如果满足以下条件：
// 密匙 b 的长度不超过密匙 a 的长度。
// 对于任意 0 <= i < length(b)，有b[i+1] - b[i] == a[i+1] - a[i]
// 现在给定了m个密匙 b 的数组，以及n个密匙 a 的数组
// 请你返回一个长度为 m 的结果数组 ans，表示每个密匙b都有多少一致的密匙
// 数组 a 和数组 b 中的元素个数均不超过 10^5
// 1 <= m, n <= 1000
// 测试链接 : https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param b int整型vector<vector<>> 
     * @param a int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
        // write code here
        build();
        for(int i = 0; i < a.size(); i++){
            string s = "";
            for(int j = 1; j < a[i].size(); j++){
                s += to_string(a[i][j] - a[i][j - 1]) + '#';
            }
            insert(s);
        }
        vector<int> ans;
        for(int i = 0; i < b.size(); i++){
            string s = "";
            for(int j = 1; j < b[i].size(); j++){
                s += to_string(b[i][j] - b[i][j - 1]) + '#';
            }
            ans.push_back(prefixNumber(s));
        }
        clear();
        return ans;
    }
    int tree[2000001][12], pass[2000001], cnt;
    void build(){
        cnt = 1;
    }
    void clear(){
        for(int i = 1; i <= cnt; i++){
            memset(tree[i], 0, sizeof(tree[i]));
            pass[i] = 0;
        }
    }
    int getpath(char cha){
        if(cha == '#'){
            return 10;
        }else if(cha == '-'){
            return 11;
        }else{
            return cha - '0';
        }
    }
    void insert(string word){
        int cur = 1;
        pass[cur]++;
        for(int i = 0, path; i < word.size(); i++){
            path = getpath(word[i]);
            if(tree[cur][path] == 0){
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
            pass[cur]++;
        }
    }
    int prefixNumber(string word){
        int cur = 1;
        for(int i = 0, path; i < word.size(); i++){
            path = getpath(word[i]);
            if(tree[cur][path] == 0){
                return 0;
            }
            cur = tree[cur][path];
        }
        return pass[cur];
    }
};

int main(){

    return 0;
}
