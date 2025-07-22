#include <bits/stdc++.h>
using namespace std;

// 归并排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
// 需要全部提交

const int N = 1e5 + 9;
int arr[N];
int help[N];

void merge(int l, int m, int r){
    int hp = l;
    int pl = l;
    int pr = m + 1;
    while(pl <= m && pr <= r){
        help[hp++] = arr[pl] <= arr[pr] ? arr[pl++] : arr[pr++];
    }
    while(pl <= m){
        help[hp++] = arr[pl++];
    }
    while(pr <= r){
        help[hp++] = arr[pr++];
    }
    for(int i = l; i <= r; i++){
        arr[i] = help[i];
    }
}

void MergeSort1(int l, int r){
    if(l == r){
        return;
    }
    int m = (l + r) / 2;
    MergeSort1(l, m);
    MergeSort1(m + 1, r);
    merge(l, m, r);
}

void MergeSort2(int n){
    for(int l, m, r, step = 1; step < n; step *= 2){
        l = 0;
        while(l < n){
            m = l + step - 1;
            if(m + 1 > n){
                break;
            }
            r = min(l + 2 * step - 1, n - 1);
            merge(l, m, r);
            l = r + 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    MergeSort1(0, n - 1);
    //MergeSort2(n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
