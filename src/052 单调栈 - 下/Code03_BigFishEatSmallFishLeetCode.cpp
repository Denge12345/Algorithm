#include <bits/stdc++.h>
using namespace std;

// 大鱼吃小鱼问题
// 给定一个数组arr，每个值代表鱼的体重
// 每一轮每条鱼都会吃掉右边离自己最近比自己体重小的鱼，每条鱼向右找只吃一条
// 但是吃鱼这件事是同时发生的，也就是同一轮在A吃掉B的同时，A也可能被别的鱼吃掉
// 如果有多条鱼在当前轮找到的是同一条小鱼，那么在这一轮，这条小鱼同时被这些大鱼吃
// 请问多少轮后，鱼的数量就固定了
// 比如 : 8 3 1 5 6 7 2 4
// 第一轮 : 8吃3；3吃1；5、6、7吃2；4没有被吃。数组剩下 8 5 6 7 4
// 第二轮 : 8吃5；5、6、7吃4。数组剩下 8 6 7
// 第三轮 : 8吃6。数组剩下 8 7
// 第四轮 : 8吃7。数组剩下 8。
// 过程结束，返回4
// 测试链接 : https://leetcode.cn/problems/steps-to-make-array-non-decreasing/

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size(), r = 0;
        vector<vector<int>> stk(n, vector<int>(2));
        int ans = 0;
        for(int i = n - 1, curTurns; i >= 0; i--){
            curTurns = 0;
            while(r > 0 && stk[r - 1][0] < nums[i]){
                curTurns = max(curTurns + 1, stk[--r][1]);
            }
            stk[r][0] = nums[i];
            stk[r++][1] = curTurns;
            ans = max(ans, curTurns);
        }
        return ans;
    }
};

int main(){

    return 0;
}
