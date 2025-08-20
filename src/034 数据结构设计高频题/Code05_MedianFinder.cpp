#include <bits/stdc++.h>
using namespace std;

// 快速获得数据流的中位数的结构
// 测试链接 : https://leetcode.cn/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(maxHeap.size() == 0 || maxHeap.top() >= num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        balance();
    }
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        }else{
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
    void balance(){
        if(abs((int)maxHeap.size() - (int)minHeap.size()) == 2){
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
};

void test(){
    MedianFinder* medianFinder = new MedianFinder();
    medianFinder->addNum(1);    // arr = [1]
    medianFinder->addNum(2);    // arr = [1, 2]
    cout << medianFinder->findMedian() << endl; // 返回 1.5 ((1 + 2) / 2)
    medianFinder->addNum(3);    // arr[1, 2, 3]
    cout << medianFinder->findMedian() << endl; // return 2.0
}

int main(){
    test();
    return 0;
}
