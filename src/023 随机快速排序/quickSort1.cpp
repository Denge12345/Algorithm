#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int arr[N];

// 随机快速排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177

//划分数组, <=x放左边, >x放右边
int parition1(int l, int r, int x){
    int a = l, xi = 0;
    for(int i = l; i <= r; i++){
        if(arr[i] <= x){
            swap(arr[a], arr[i]);
            if(arr[a] == x){
                xi = a;
            }
            a++;
        }
    }
    swap(arr[xi], arr[a - 1]);
    return a - 1;
}

void quickSort1(int l, int r){
    if(l >= r){
        return;
    }
    int x = arr[l + rand() % (r - l + 1)];
    int m = parition1(l, r, x);
    quickSort1(l, m - 1);
    quickSort1(m + 1, r);
}

int first, last;

void parition2(int l, int r, int x){
    first = l;
    last = r;
    int i = l;
    while(i <= last){
        if(arr[i] == x){
            i++;
        }else if(arr[i] < x){
            swap(arr[first++], arr[i++]);
        }else{
            swap(arr[last--], arr[i]);
        }
    }
}

void quickSort2(int l, int r){
    if(l >= r){
        return;
    }
    int x = arr[l + rand() % (r - l + 1)];
    parition2(l, r, x);
    int left = first;
    int right = last;
    quickSort2(l, left - 1);
    quickSort2(right + 1, r);
}

int main(){
    srand((unsigned int)time(NULL));
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort1(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
