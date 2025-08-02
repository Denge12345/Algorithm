#include <bits/stdc++.h>
using namespace std;

int BASE = 10;
int help[15], cnt[15];

void sort(int arr[], int n, int bit){
    for(int offset = 1; bit > 0; offset *= BASE, bit--){
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++){
            cnt[(arr[i] / offset) % BASE]++;
        }
        for(int i = 1; i < BASE; i++){
            cnt[i] = cnt[i] + cnt[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            help[--cnt[(arr[i] / offset) % BASE]] = arr[i];
        }
        for(int i = 0; i < n; i++){
            arr[i] = help[i];
        }
    }
}

int bits(int num){
    int res = 0;
    while(num){
        num /= BASE;
        res++;
    }
    return res;
}

void radixSort(int arr[], int n){
    int mina = INT_MAX, maxa = INT_MIN;
    for(int i = 0; i < n; i++){
        mina = min(arr[i], mina);
    }
    for(int i = 0; i < n; i++){
        arr[i] -= mina;
        maxa = max(arr[i], maxa);
    }
    sort(arr, n, bits(maxa));
    for(int i = 0; i < n; i++){
        arr[i] += mina;
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr1[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    int arr2[10] = {25, 231, 542, 603, 107, 283, 549, 404, 350, 336};
    cout << "排序前: " << endl;
    printArr(arr1, 10);
    radixSort(arr1, 10);
    cout << "排序后: " << endl;
    printArr(arr1, 10);
    cout << "排序前: " << endl;
    printArr(arr2, 10);
    radixSort(arr2, 10);
    cout << "排序后: " << endl;
    printArr(arr2, 10);
    return 0;
}
