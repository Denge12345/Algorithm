#include <bits/stdc++.h>
using namespace std;

//找到升序数组中第一个>=num的元素的下标

//暴力解
//保证arr升序才能使用
int right(vector<int>& arr, int target){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] >= target){
            return i;
        }
    }
    return -1;
}

//待测的最优解
//保证arr升序才能使用
int findLeft(vector<int>& arr, int target){
    int l = 0, r = arr.size() - 1;
    int ans = -1;
    while(l <= r){
        int m = (l + r) / 2;
	//1 3 3 5 6 7 8 8 9 target = 7
	//1 : l = 0, r = 7 m = 3; 5 < 7 l = 4
	//2 : l = 4, r = 7 m = 6; 8 >= 7 ans = 6, r = 5
	//3 : l = 4, r = 5 m = 4; 6 < 7 l = 5
	//4 : l = 5, r = 5 m = 5; 7 >= 7 ans = 5, r = 4
	//r < l 结束
        if(arr[m] >= target){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    return ans;
}

//生成随机数组 
vector<int> randomSimple(int n, int v){
	vector<int> tmp;
	for(int i = 0; i < n; i++){
		tmp.push_back(rand() % v + 1);
	}
	return tmp;
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
    int N = 100;
    int V = 1000;
    int testTimes = 500000;
    cout << "测试开始" << endl;
    for(int i = 1; i <= testTimes; i++){
    	int n = rand() % N + 1;
    	vector<int> a = randomSimple(n, V);
    	sort(a.begin(), a.end());
    	int num = rand() % V + 1;
        if(right(a, num) != findLeft(a, num)){
            cout << "样例 " << i << " 出错了" << endl;
            printArray(a);
            cout << "num = " << num << endl;
            cout << "right: " << right(a, num) << endl;
            cout << "findLeft: " << findLeft(a, num) << endl;
        }
	}
    cout << "测试结束" << endl; 
    return 0;
}
