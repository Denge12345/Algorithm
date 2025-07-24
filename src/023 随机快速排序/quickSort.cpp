#include <bits/stdc++.h>
using namespace std;

//快速排序经典版
int partition1(int arr[], int l, int r, int x){
    //a : arr[0...a-1]是<=x的区域
    //xi : 记录<=x区域上任何一个x的位置
    int a = l, xi = 0;
    for(int i = l; i <= r; i++){
        //划分数组 <=x放左边, >x放右边
        if(arr[i] <= x){
            swap(arr[a], arr[i]);
            if(arr[a] == x){
                xi = a;
            }
            a++;
        }
    }
    //确保划分后<=x的区域最后一个数字是x
    swap(arr[xi], arr[a - 1]);
    return a - 1;
}

void quickSort1(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    //在arr[l..r]范围上随机选一个数字作为基准值
    int x = arr[l + rand() % (r - l + 1)];
    int m = partition1(arr, l, r, x);
    quickSort1(arr, l, m - 1);
    quickSort1(arr, m + 1, r);
}

//快速排序改进版(荷兰国旗问题)
int first, last;

void partition2(int arr[], int l, int r, int x){
    //[first, last]表示==x的左右边界
    first = l;
    last = r;
    int i = l;
    while(i <= last){
        //划分数组 <x放左边 ==x放中间 >x放右边
        if(arr[i] == x){
            i++;
        }else if(arr[i] < x){
            swap(arr[first++], arr[i++]);
        }else{
            swap(arr[last--], arr[i]);
        }
    }
}

void quickSort2(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    //在arr[l..r]范围上随机选一个数字作为基准值
    int x = arr[l + rand() % (r - l + 1)];
    partition2(arr, l, r, x);
    int left = first;
    int right = last;
    quickSort2(arr, l, left - 1);
    quickSort2(arr, right + 1, r);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    srand((unsigned int)time(NULL));
    int arr1[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    int arr2[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    cout << "===快速排序经典版测试===" << endl;
    cout << "排序前: ";
    printArray(arr1, 10);
    cout << "排序后: ";
    quickSort1(arr1, 0, 9);
    printArray(arr1, 10);
    cout << "===快速排序改进版测试===" << endl;
    cout << "排序前: ";
    printArray(arr2, 10);
    cout << "排序后: ";
    quickSort2(arr2, 0, 9);
    printArray(arr2, 10);
    return 0;
}
