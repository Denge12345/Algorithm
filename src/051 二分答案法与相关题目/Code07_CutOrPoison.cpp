#include <bits/stdc++.h>
using namespace std;

// 刀砍毒杀怪兽问题
// 怪兽的初始血量是一个整数hp，给出每一回合刀砍和毒杀的数值cuts和poisons
// 第i回合如果用刀砍，怪兽在这回合会直接损失cuts[i]的血，不再有后续效果
// 第i回合如果用毒杀，怪兽在这回合不会损失血量，但是之后每回合都损失poisons[i]的血量
// 并且你选择的所有毒杀效果，在之后的回合都会叠加
// 两个数组cuts、poisons，长度都是n，代表你一共可以进行n回合
// 每一回合你只能选择刀砍或者毒杀中的一个动作
// 如果你在n个回合内没有直接杀死怪兽，意味着你已经无法有新的行动了
// 但是怪兽如果有中毒效果的话，那么怪兽依然会在血量耗尽的那回合死掉
// 返回至少多少回合，怪兽会死掉
// 数据范围 : 
// 1 <= n <= 10^5
// 1 <= hp <= 10^9
// 1 <= cuts[i]、poisons[i] <= 10^9
// 本题来自真实大厂笔试，找不到测试链接，所以用对数器验证

int f1(vector<int>& cuts, vector<int>& poisons, int i, int r, int p, vector<vector<vector<int>>>& dp){
    r -= p;
    if(r <= 0){
        return i + 1;
    }
    if(i == cuts.size()){
        if(p == 0){
            return INT_MAX;
        }else{
            return cuts.size() + 1 + (r + p - 1) / p;
        }
    }
    if(dp[i][r][p] != 0){
        return dp[i][r][p];
    }
    int p1 = r <= cuts[i] ? (i + 1) : f1(cuts, poisons, i + 1, r - cuts[i], p, dp);
    int p2 = f1(cuts, poisons, i + 1, r, p + poisons[i], dp);
    int ans = min(p1, p2);
    dp[i][r][p] = ans;
    return ans;
}

int fast1(vector<int>& cuts, vector<int>& poisons, int hp){
    int sum = 0;
    for(int num : poisons){
        sum += num;
    }
    vector<vector<vector<int>>> dp(cuts.size(), vector<vector<int>>(hp + 1, vector<int>(sum + 1, 0)));
    return f1(cuts, poisons, 0, hp, 0, dp);
}

bool f(vector<int> cuts, vector<int> poisons, int hp, int limit){
    int n = min((int)cuts.size(), limit);
    for(int i = 0, j = 1; i < n; i++, j++){
        hp -= max((long long)cuts[i], (long long)(limit - j) * (long long)poisons[i]);
        if(hp <= 0){
            return true;
        }
    }
    return false;
}

int fast2(vector<int> cuts, vector<int> poisons, int hp){
    int ans = INT_MAX;
    for(int l = 1, r = hp + 1, m; l <= r; ){
        m = l + (r - l) / 2;
        if(f(cuts, poisons, hp, m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}

//生成随机数组 
vector<int> randomArray(int n, int v){
    vector<int> tmp;
    for(int i = 0; i < n; i++){
    	//生成元素大小在1~v的数组 
        tmp.push_back(rand() % v + 1);
    }
    return tmp;
}

int main(){
    srand((unsigned int)time(0));
    cout << "测试开始" << endl;
    int N = 30;
    int V = 20;
    int H = 300;
    int testTimes = 10000;
    for(int i = 0; i < testTimes; i++){
        int n = rand() % N + 1;
        vector<int> cuts = randomArray(n, V);
        vector<int> poisons = randomArray(n, V);
        int hp = rand() % H + 1;
        int ans1 = fast1(cuts, poisons, hp);
        int ans2 = fast2(cuts, poisons, hp);
        if(ans1 != ans2){
            cout << "出错了" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
