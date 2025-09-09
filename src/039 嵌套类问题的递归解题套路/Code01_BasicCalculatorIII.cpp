#include <bits/stdc++.h>
using namespace std;

// 含有嵌套的表达式求值
// 力扣上本题为会员题，所以额外提供了牛客网的测试链接
// 如果在牛客网上提交，请将函数名从calculate改为solve
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
// 测试链接 : https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here
        where = 0;
        return f(s, 0);
    }
    int where;
    int f(string& s, int i){
        int cur = 0;
        vector<int> numbers;
        vector<char> operators;
        while(i < s.size() && s[i] != ')'){
            if(s[i] >= '0' && s[i] <= '9'){
                cur = cur * 10 + s[i++] - '0';
            }else if(s[i] != '('){
                add(numbers, operators, cur, s[i++]);
                cur = 0;
            }else{
                cur = f(s, i + 1);
                i = where + 1;
            }
        }
        add(numbers, operators, cur, '+');
        where = i;
        return compute(numbers, operators);
    }
    void add(vector<int>& numbers, vector<char>& operators, int cur, char op){
        int n = numbers.size();
        if(n == 0 || operators[n - 1] == '+' || operators[n - 1] =='-'){
            numbers.push_back(cur);
            operators.push_back(op);
        }else{
            int topNumber = numbers[n - 1];
            int topOp = operators[n - 1];
            if(topOp == '*'){
                numbers[n - 1] = topNumber * cur;
            }else{
                numbers[n - 1] = topNumber / cur;
            }
            operators[n - 1] = op;
        }
    }
    int compute(vector<int>& numbers, vector<char>& operators){
        int n = numbers.size();
        int ans = numbers[0];
        for(int i = 1; i < n; i++){
            ans += operators[i - 1] == '+' ? numbers[i] : -numbers[i];
        }
        return ans;
    }
};

int main(){

    return 0;
}
