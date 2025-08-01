#include <bits/stdc++.h>
using namespace std;

// 最多线段重合问题
// 填函数风格,需要leetcode会员
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/

const int N = 1e4 + 9;
pair<int, int> a[N];

// acm风格
// 测试链接 : https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
void test0(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, [](pair<int, int>& u, pair<int, int>& v){return u.first < v.first;});
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i++){
        while(!heap.empty() && heap.top() <= a[i].first){
            heap.pop();
        }
        heap.push(a[i].second);
        ans = max(ans, (int)heap.size());
    }
    cout << ans << endl;
}

//用手写堆实现
int heap[10009], Size;

void add(int x){
    heap[Size] = x;
    int i = Size++;
    while(heap[i] < heap[(i - 1) / 2]){
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop(){
    swap(heap[0], heap[--Size]);
    int i = 0, l = 1;
    while(l < Size){
        int best = l + 1 < Size && heap[l + 1] < heap[l] ? l + 1 : l;
        best = heap[best] < heap[i] ? best : i;
        if(best == i){
            break;
        }
        swap(heap[i], heap[best]);
        i = best;
        l = 2 * i + 1;
    }
}

void test1(){
    Size = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n, [](pair<int, int>& u, pair<int, int>& v){return u.first < v.first;});
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(Size > 0 && heap[0] <= a[i].first){
            pop();
        }
        add(a[i].second);
        ans = max(ans, Size);
    }
    cout << ans << endl;
}

// 填函数风格,不需要leetcode会员,但是题目有略微差别
// 测试链接 : https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/
// 直接提交如下类即可
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& u, vector<int>& v){return u[0] < v[0];});
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < n; i++){
            while(!heap.empty() && heap.top() < intervals[i][0]){
                heap.pop();
            }
            heap.push(intervals[i][1]);
            ans = max(ans, (int)heap.size());
        }
        return ans;
    }
};

void test2(){
    vector<vector<int>> intervals1 = {{5, 10},{6,8},{1,5},{2,3},{1,10}};
    vector<vector<int>> intervals2 = {{1,3},{5,6},{8,10},{11,13}};
    Solution solution;
    cout << solution.minGroups(intervals1) << endl;
    cout << solution.minGroups(intervals2) << endl;
}

int main(){
    cout << "=====acm风格测试(STL)=====" << endl;
    test0();
    cout << "=====acm风格测试(手写堆)=====" << endl;
    test1();
    cout << "=====填函数风格测试=====" << endl;
    test2();
    return 0;
}
