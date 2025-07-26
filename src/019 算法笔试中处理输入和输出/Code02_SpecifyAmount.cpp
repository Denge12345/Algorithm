#include <bits/stdc++.h>
using namespace std;

//acm风格
//https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?

//提交时要提交全部函数,或者将test1中的代码复制到main中后再提交
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

void test1(){
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    cout << maxSumSubmatrix(mat, n, m);
}

int main(){
    test1();
    return 0;
}
