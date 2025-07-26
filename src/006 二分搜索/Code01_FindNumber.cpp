#include <bits/stdc++.h>
using namespace std;

//判断升序数组中是否存在num

//暴力解 
bool right(vector<int>& arr, int target){
	int n = arr.size();
	for(int i = 0; i < n; i++){
		if(arr[i] == target){
			return true;
		}
	}
	return false;
}

//待测的最优解
//保证arr有序才能使用 
bool exist(vector<int>& arr, int target){
	int n = arr.size();
	int l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(arr[m] == target){
			return true;
		}else if(arr[m] > target){
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	return false;
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
    	if(right(a, num) != exist(a, num)){
    		cout << "样例 " << i << " 出错了" << endl;
    		printArray(a);
    		cout << "num = " << num << endl;
    		cout << "right: " << num << (right(a, num) ? " 存在" : " 不存在") << endl;
    		cout << "exist: " << num << (exist(a, num) ? " 存在" : " 不存在") << endl;
		}
	}
    cout << "测试结束" << endl; 
    return 0;
}
