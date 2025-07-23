#include <bits/stdc++.h>
using namespace std;

int help[10];

void merge(int arr[], int l, int m, int r){
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

void MergeSort1(int arr[], int l, int r){
    if(l == r){
        return;
    }
    int m = (l + r) / 2;
    MergeSort1(arr, l, m);
    MergeSort1(arr, m + 1, r);
    merge(arr, l, m, r);
}

void MergeSort2(int arr[], int n){
    for(int l, m, r, step = 1; step < n; step *= 2){
        l = 0;
        while(l < n){
            m = l + step - 1;
            if(m + 1 > n){
                break;
            }
            r = min(l + 2 * step - 1, n - 1);
            merge(arr, l, m, r);
            l = r + 1;
        }
    }
}

void printArray(int arr[]){
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr1[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    int arr2[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    cout << "===归并排序递归写法===" << endl;
    cout << "排序前: ";
    printArray(arr1);
    MergeSort1(arr1, 0, 9);
    cout << "排序后: ";
    printArray(arr1);
    cout << "===归并排序非递归写法===" << endl;
    cout << "排序前: ";
    printArray(arr2);
    MergeSort2(arr2, 10);
    cout << "排序后: ";
    printArray(arr2);
    return 0;
}
