#include <bits/stdc++.h>
using namespace std;

// 判断一个数字是否是若干数量(数量>1)的连续正整数的和
bool is1(int num){
    for(int start = 1, sum; start <= num; start++){
        sum = start;
        for(int j = start + 1; j <= num; j++){
            if(sum + j > num){
                break;
            }
            if(sum + j == num){
                return true;
            }
            sum += j;
        }
    }
    return false;
}

bool is2(int num){
    return (num & (num - 1)) != 0;
}

int main(){
    for(int num = 1; num < 200; num++){
        cout << num << " : " << (is1(num) ? "T" : "F") << endl;
    }
    return 0;
}
