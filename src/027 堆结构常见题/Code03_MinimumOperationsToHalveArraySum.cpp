#include <bits/stdc++.h>
using namespace std;

// 将数组和减半的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
// 将类名修改为Solution后提交即可
class Solution1 {
public:
    int halveArray1(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        priority_queue<double> heap;
        for(int i = 0; i < n; i++){
            heap.push(nums[i]);
            sum += nums[i];
        }
        sum /= 2;
        int ans = 0;
        for(double minus = 0, cur; minus < sum; ans++, minus += cur){
            cur = heap.top() / 2;
            heap.pop();
            heap.push(cur);
        }
        return ans;
    }
};

void test1(){
    cout << "=====STL优先队列实现测试=====" << endl;
    vector<int> nums1 = {5, 19, 8, 1};
    vector<int> nums2 = {3, 8, 20};
    Solution1 solution1;
    cout << solution1.halveArray1(nums1) << endl;
    cout << solution1.halveArray1(nums2) << endl;
}

// 将类名修改为Solution后提交即可
class Solution2 {
public:
    long long heap[100009], size;
    void heapify(int i){
        int l = 2 * i + 1;
        while(l < size){
            int best = l + 1 < size && heap[l + 1] > heap[l] ? l + 1 : l;
            best = heap[best] > heap[i] ? best : i;
            if(best == i){
                break;
            }
            swap(heap[best], heap[i]);
            i = best;
            l = 2 * i + 1;
        }
    }
    int halveArray2(vector<int>& nums) {
        size = nums.size();
        long long sum = 0;
        for(int i = size - 1; i >= 0; i--){
            heap[i] = (long long)nums[i] << 20;
            sum += heap[i];
            heapify(i);
        }
        sum /= 2;
        int ans = 0;
        for(long long minus = 0; minus < sum; ans++){
            heap[0] /= 2;
            minus += heap[0];
            heapify(0);
        }
        return ans;
    }
};

void test2(){
    cout << "=====手写堆实现测试=====" << endl;
    vector<int> nums1 = {5, 19, 8, 1};
    vector<int> nums2 = {3, 8, 20};
    Solution2 solution2;
    cout << solution2.halveArray2(nums1) << endl;
    cout << solution2.halveArray2(nums2) << endl;
}

int main(){
    test1();
    test2();
    return 0;
}
