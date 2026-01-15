#include <bits/stdc++.h>
using namespace std;

// 你可以安排的最多任务数目
// 给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成
// 需要的力量值保存在下标从 0 开始的整数数组 tasks 中，
// 第i个任务需要 tasks[i] 的力量才能完成
// 每个工人的力量值保存在下标从 0 开始的整数数组workers中，
// 第j个工人的力量值为 workers[j]
// 每个工人只能完成一个任务，且力量值需要大于等于该任务的力量要求值，即workers[j]>=tasks[i]
// 除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength
// 你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸
// 给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength
// 请你返回 最多 有多少个任务可以被完成。
// 测试链接 : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

class Solution {
public:
    vector<int> ts = vector<int>(50001);
    vector<int> ws = vector<int>(50001);
    vector<int> q = vector<int>(50001);
    int h, t;
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        ts = tasks;
        ws = workers;
        sort(ts.begin(), ts.end());
        sort(ws.begin(), ws.end());
        int tsize = ts.size();
        int wsize = ws.size();
        int ans = 0;
        for(int l = 0, r = min(tsize, wsize), m; l <= r;){
            // 一定要完成的任务数量
            m = (l + r) / 2;
            if(f(0, m - 1, wsize - m, wsize - 1, strength, pills)){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return ans;
    }
    // ts[tl..tr]需要力量最小的几个任务
    // ws[wl..wr]力量值最大的几个工人
    // 药效是s，一共有的药pills个
    // 在药的数量不超情况下，能不能每个工人都做一个任务
    bool f(int tl, int tr, int wl, int wr, int s, int pills){
        h = t = 0;
        // 已经使用的药的数量
        int cnt = 0;
        for(int i = wl, j = tl; i <= wr; i++){
            // i : 工人的编号
            // j : 任务的编号
            for(; j <= tr && ts[j] <= ws[i]; j++){
                // 工人不吃药的情况下，解锁任务
                q[t++] = j;
            }
            if(h < t && ts[q[h]] <= ws[i]){
                // 不吃药，完成队头，耗费力量最小的任务
                h++;
            }else{
                // 吃药之后的逻辑
                for(; j <= tr && ts[j] <= ws[i] + s; j++){
                    // 工人吃药的情况下，解锁任务
                    q[t++] = j;
                }
                if(h < t){
                    // 药的使用数量+1
                    // 完成队尾，耗费力量最大的任务
                    cnt++;
                    t--;
                }else{
                    return false;
                }
            }
            return cnt <= pills;
        }
    }
};

int main(){

    return 0;
}
