#include <bits/stdc++.h>
using namespace std;

// 计算等位时间
// 给定一个数组arr长度为n，表示n个服务员，每服务一个人的时间
// 给定一个正数m，表示有m个人等位，如果你是刚来的人，请问你需要等多久？
// 假设m远远大于n，比如n <= 10^3, m <= 10^9，该怎么做是最优解？
// 谷歌的面试，这个题连考了2个月
// 找不到测试链接，所以用对数器验证

struct Node{
    int a, b;
    bool operator < (Node u) const {
        return a > u.a;
    }
};

int waitingTime1(vector<int>& arr, int m){
    priority_queue<Node> heap;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        heap.push({0, arr[i]});
    }
    for(int i = 0; i < m; i++){
        Node cur = heap.top();
        heap.pop();
        cur.a += cur.b;
        heap.push(cur);
    }
    return heap.top().a;
}

// 每个服务员都工作time时间,能接待多少人
int f(vector<int>& arr, int time){
    int ans = 0;
    for(int num : arr){
        ans += (time / num) + 1;
    }
    return ans;
}

int waitingTime2(vector<int>& arr, int w){
    int Min = INT_MAX;
    for(int x : arr){
        Min = min(Min, x);
    }
    int ans = 0;
    for(int l = 0, r = Min * w, m; l <= r; ){
        // m表示让服务员工作的时间
        m = (l + r) / 2;
        // 能够给几个客人提供服务
        if(f(arr, m) >= w + 1){
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
    int N = 50;
    int V = 30;
    int M = 3000;
    int testTime = 20000;
    for(int i = 0; i < testTime; i++){
        int n = rand() % N + 1;
        vector<int> arr = randomArray(n, V);
        int m = rand() % M + 1;
        int ans1 = waitingTime1(arr, m);
        int ans2 = waitingTime2(arr, m);
        if(ans1 != ans2){
            cout << "出错了" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
