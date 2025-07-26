#include <bits/stdc++.h>
using namespace std;

//填函数风格
//https://www.nowcoder.com/practice/840eee05dccd4ffd8f9433ce8085946b

//提交时需要提交除main和test以外的所有函数
int maxSumSubarray(vector<int> arr, int m){
    int Max = INT_MIN;
    int cur = 0;
    for(int i = 0; i < m; i++){
        cur += arr[i];
        Max = max(Max, cur);
        cur = cur < 0 ? 0 : cur;
    }
    return Max;
}

int maxSumSubmatrix(vector<vector<int>> mat, int n, int m){
    int Max = INT_MIN;
    for(int i = 0; i < n; i++){
        vector<int> arr(m);
        for(int j = i; j < n; j++){
            for(int k = 0; k < m; k++){
                arr[k] += mat[j][k];
            }
            Max = max(Max, maxSumSubarray(arr, m));
        }
    }
    return Max;
}

int sumOfSubMatrix(vector<vector<int> > mat, int n) {
    // write code here
    return maxSumSubmatrix(mat, n, n);
}

//测试用
void test1(){
    vector<vector<int>> mat(3, vector<int>(3, 0));
    mat[0][0] = 1, mat[0][1] = 2, mat[0][2] = -3;
    mat[1][0] = 3, mat[1][1] = 4, mat[1][2] = -5;
    mat[2][0] = -5, mat[2][1] = -6, mat[2][2] = -7;
    int n = 3;
    cout << sumOfSubMatrix(mat, n) << endl;
}

int main(){
    test1();
    return 0;
}
