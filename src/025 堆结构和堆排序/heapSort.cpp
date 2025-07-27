#include <bits/stdc++.h>
using namespace std;

//向堆中加入一个数
void heapInsert(int arr[], int i){
    //当前元素是否大于他的父节点
    while(arr[i] > arr[(i - 1) / 2]){
        //大于就交换，直到小于等于或到堆顶
        swap(arr[(i - 1) / 2], arr[i]);
        i = (i - 1) / 2;
    }
}

//i位置的数，向下调整大根堆
void heapify(int arr[], int i, int size){
    //i的左子节点
    int l = 2 * i + 1;
    //如果i有左子节点
    while(l < size){
        //判断i的两个子节点中，最大的子节点是哪个
        int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
        //判断i的子节点是否大于i
        best = arr[best] > arr[i] ? best : i;
        //如果最大的是i本身，就不下移
        if(best == i){
            break;
        }
        swap(arr[best], arr[i]);
        //继续向下移动
        i = best;
        l = 2 * i + 1;
    }
}

//从顶到底建立大根堆,O(nlogn)
//堆排序,O(nlogn)
//整体时间复杂度,O(nlogn)
void heapSort1(int arr[], int n){
    for(int i = 0; i < n; i++){
        heapInsert(arr, i);
    }
    int size = n;
    while(size > 1){
        swap(arr[0], arr[--size]);
        heapify(arr, 0, size);
    }
}

//从底到顶建立大根堆,O(n)
//堆排序,O(nlogn)
//整体时间复杂度,O(nlogn)
void heapSort2(int arr[], int n){
    for(int i = n - 1; i >= 0; i--){
        heapify(arr, i, n);
    }
    int size = n;
    while(size > 1){
        swap(arr[0], arr[--size]);
        heapify(arr, 0, size);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    //下标从0开始,下标为i的父节点为(i - 1) / 2
    //父节点下标为i的左子节点为2 * i + 1
    //父节点下标为i的右子节点为2 * i + 2
    int arr1[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    int arr2[10] = {4, 2, 8, 1, 5, 7, 10, 3, 9, 6};
    cout << "===从顶到底建立大根堆===" << endl;
    cout << "排序前: ";
    printArray(arr1, 10);
    heapSort1(arr1, 10);
    cout << "排序后: ";
    printArray(arr1, 10);
    cout << "===从底到顶建立大根堆===" << endl;
    cout << "排序前: ";
    printArray(arr2, 10);
    heapSort1(arr2, 10);
    cout << "排序后: ";
    printArray(arr2, 10);
    return 0;
}
