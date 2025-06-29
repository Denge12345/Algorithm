#include<bits/stdc++.h>
using namespace std;

//不使用vector的版本

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

//生成随机数组 
void randomArray(int n, int v, int arr[]){
    for(int i = 0; i < n; i++){
    	//生成元素大小在1~v的数组 
        arr[i] = rand() % v + 1;
    }
}

//拷贝数组 
void copyArray(int n, int origin[], int target[]){
	for(int i = 0; i < n; i++){
		target[i] = origin[i];
	}
}

//判断最优解是否和暴力解相同 
bool judge(int n, int correct[], int test[]){
    for(int i = 0; i < n; i++){
        if(correct[i] != test[i]){
            return false;
        }
    }
    return true;
}

void printArray(int n, int arr[]){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
    srand((unsigned int)time(NULL));
    //分别表示随机数组,冒泡排序数组,选择排序数组,插入排序数组
    int a[205] = {0};
    int ba[205] = {0};
    int sa[205] = {0};
    int ia[205] = {0};
    //随机数组长度
    int N = rand() % 200 + 1;
    //随机数组元素的值,在1~V等概率随机
    int V = 1000;
    //测试次数
    int testTimes = 50000;
    cout << "测试开始" << endl;
    for(int i = 1; i <= testTimes; i++){
        //得到一个随机长度,长度在[1~N]
        int n = rand() % N + 1;
        //生成随机数组
        randomArray(n, V, a);
        copyArray(n, a, ba);
        copyArray(n, a, sa);
        copyArray(n, a, ia); 
        bubble_sort(n, ba);
        selection_sort(n, sa);
        insertion_sort(n, ia);
        //假设冒泡排序是正确的
        if(!judge(n, ba, sa)){
            cout << "选择排序测试样例 " << i << " 出错了!" << endl;
            cout << "原数组: " << endl;
			printArray(n, a);
			cout << "正确数组: " << endl;
			printArray(n, ba);
			cout << "错误数组: " << endl;
			printArray(n, sa); 
        }
        if(!judge(n, ba, ia)){
            cout << "插入排序测试样例 " << i << " 出错了!" << endl;
            cout << "原数组: " << endl;
			printArray(n, a);
			cout << "正确数组: " << endl;
			printArray(n, ba);
			cout << "错误数组: " << endl;
			printArray(n, ia); 
        }
    }
    cout << "测试结束" << endl;
    return 0;
}
