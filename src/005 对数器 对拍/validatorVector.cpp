#include <bits/stdc++.h>
using namespace std;

//使用vector的版本

//选择排序 
void selection_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[minIndex] > arr[j]) minIndex = j;
        }
        if(minIndex != i){
            swap(arr[minIndex], arr[i]);
        }
    }
}

//冒泡排序 
void bubble_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//插入排序 
void insertion_sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int j = i - 1;
        while(arr[j] > arr[j + 1] && j >= 0){
        	swap(arr[j], arr[j + 1]);
        	j--;
		}
    }
}

//生成随机数组 
vector<int> randomArray(int n, int v){
    vector<int> tmp;
    for(int i = 0; i < n; i++){
    	//生成元素大小在1~v的数组 
        tmp.push_back(rand() % v + 1);
    }
    return tmp;
}

//判断最优解是否和暴力解相同 
bool judge(vector<int>& correct, vector<int>& test){
    int n = correct.size();
    for(int i = 0; i < n; i++){
        if(correct[i] != test[i]){
            return false;
        }
    }
    return true;
}

void printArray(vector<int>& arr){
    int n = arr.size();
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
    srand((unsigned int)time(NULL));
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
        vector<int> a = randomArray(n, V);
        vector<int> bubbleA = a;
        vector<int> selectionA = a;
        vector<int> insertionA = a;
        bubble_sort(bubbleA);
        selection_sort(selectionA);
        insertion_sort(insertionA);
        if(!judge(bubbleA, selectionA)){
            cout << "选择排序测试样例 " << i << " 出错了!" << endl;
            cout << "原数组: " << endl;
			printArray(a);
			cout << "正确数组: " << endl;
			printArray(bubbleA);
			cout << "错误数组: " << endl;
			printArray(selectionA); 
        }
        if(!judge(bubbleA, insertionA)){
            cout << "插入排序测试样例 " << i << " 出错了!" << endl;
            cout << "原数组: " << endl;
			printArray(a);
			cout << "正确数组: " << endl;
			printArray(bubbleA);
			cout << "错误数组: " << endl;
			printArray(insertionA); 
        }
    }
    cout << "测试结束" << endl;
    return 0;
}