#include <bits/stdc++.h>
using namespace std;

//acm风格
//在函数外开大空间静态数组
//空间大小由题目的数据范围决定
//https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?

//题目给定的最大数据量
const int N = 205;
int mat[N][N], arr[N], n, m;

//提交时要提交全部函数,或者将test1中的代码复制到main中后再提交
int maxSumSubarray(){
    int Max = INT_MIN;
    int cur = 0;
    for(int i = 0; i < m; i++){
        cur += arr[i];
        Max = max(Max, cur);
        cur = cur < 0 ? 0 : cur;
    }
    return Max;
}

int maxSumSubmatrix(){
    int Max = INT_MIN;
    for(int i = 0; i < n; i++){
        //因为之前的过程可能用过辅助数组
        //为了让之前结果不干扰到这次运行,需要自己清空辅助数组需要用到的部分
        memset(arr, 0, sizeof(arr));
        for(int j = i; j < n; j++){
            for(int k = 0; k < m; k++){
                arr[k] += mat[j][k];
            }
            Max = max(Max, maxSumSubarray());
        }
    }
    return Max; 
}

void test1(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    cout << maxSumSubmatrix();
}

int main(){
    test1();
    return 0;
}
