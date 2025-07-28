#include <bits/stdc++.h>
using namespace std;

// 堆结构和堆排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177

const int N = 1e5 + 9;
int a[N];

void heapInsert(int i){
    while(a[i] > a[(i - 1) / 2]){
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i, int size){
    int l = 2 * i + 1;
    while(l < size){
        int best = l + 1 < size && a[l] < a[l + 1] ? l + 1 : l;
        best = a[i] > a[best] ? i : best;
        if(best == i){
            break;
        }
        swap(a[i], a[best]);
        i = best;
        l = 2 * i + 1;
    }
}

void heapSort1(int n){
    for(int i = 0; i < n; i++){
        heapInsert(i);
    }
    int size = n;
    while(size > 1){
        swap(a[0], a[--size]);
        heapify(0, size);
    }
}

void heapSort2(int n){
    for(int i = n - 1; i >= 0; i--){
        heapify(i, n);
    }
    int size = n;
    while(size > 1){
        swap(a[0], a[--size]);
        heapify(0, size);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    heapSort1(n);
    //heapSort2(n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
