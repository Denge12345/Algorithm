#include <bits/stdc++.h>
using namespace std;

// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a

class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> generatePermutation(string s) {
        // write code here
        vector<string> ans;
        set<string> st;
        string path = "";
        f1(0, s, path, st);
        for(string i : st){
            ans.push_back(i);
        }
        return ans;
    }
    void f1(int i, string& s, string& path, set<string>& st){
        if(i == s.size()){
            st.insert(path);
        }else{
            path.push_back(s[i]);
            f1(i + 1, s, path, st);
            path.pop_back();
            f1(i + 1, s, path, st);
        }
    }
};

class Solution2 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> generatePermutation(string s) {
        // write code here
        vector<string> ans;
        set<string> st;
        string path = "";
        f2(0, s, path, 0, st);
        for(string i : st){
            ans.push_back(i);
        }
        return ans;
    }
    void f2(int i, string& s, string& path, int size, set<string>& st){
        if(i == s.size()){
            st.insert(path.substr(0, size));
        }else{
            if(size >= path.size()){
                path.resize(size + 1);
            }
            path[size] = s[i];
            f2(i + 1, s, path, size + 1, st);
            f2(i + 1, s, path, size, st);
        }
    }
};

int main(){
    
    return 0;
}
