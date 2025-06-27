#include <bits/stdc++.h>
using namespace std;

//交换两个元素 
void swapElement(int i, int j, int arr[]){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

//选择排序 
void selection_sort(int n, int arr[]){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[minIndex] > arr[j]) minIndex = j;
        }
        if(minIndex != i){
            swapElement(i, minIndex, arr);
        }
    }
}

//冒泡排序 
void bubble_sort(int n, int arr[]){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swapElement(j, j + 1, arr);
            }
        }
    }
}

//插入排序 
void insertion_sort(int n, int arr[]){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        while(arr[j] > arr[j + 1] && j >= 0){
        	swapElement(j, j + 1, arr);
        	j--;
		}
    }
}

//输出数组 
void printArr(int n, int arr[]){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//生成随机数组 
void randomSimple(int n, int arr[]){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 10 + 5;
    }
}

int main(){
    srand((unsigned int)time(NULL));
    int a[20] = {0};
    //随机数组大小(5 ~ 14)
    int n = rand() % 10 + 5;
    cout << "冒泡排序" << endl;
    randomSimple(n, a);
    cout << "排序前" << endl;
    printArr(n, a);
    cout << "排序后" << endl;
    bubble_sort(n, a);
    printArr(n, a);
    cout << "选择排序" << endl;
    randomSimple(n, a);
    cout << "排序前" << endl;
    printArr(n, a);
    cout << "排序后" << endl;
    selection_sort(n, a);
    printArr(n, a);
    cout << "插入排序" << endl;
    randomSimple(n, a);
    cout << "排序前" << endl;
    printArr(n, a);
    cout << "排序后" << endl;
    insertion_sort(n, a);
    printArr(n, a);
    return 0;
}
