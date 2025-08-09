#include <bits/stdc++.h>
using namespace std;

// 已知n是非负数
// 返回大于等于n的最小的2某次方
// 如果int范围内不存在这样的数，返回整数最小值

int near2power(int n){
    if(n <= 0){
        return 1;
    }
    n--;
    unsigned int un = static_cast<unsigned int>(n);
    un |= un >> 1;
    un |= un >> 2;
    un |= un >> 4;
    un |= un >> 8;
    un |= un >> 16;
    return static_cast<int>(un + 1);
}

int main(){
    int number = 100;
    cout << near2power(number) << endl;
    return 0;
}
