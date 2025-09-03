#include <bits/stdc++.h>
using namespace std;

void f(int i, string from, string to, string other){
    if(i == 1){
        cout << "移动圆盘 1 从 " << from << " 到 " << to << endl;
    }else{
        f(i - 1, from, other, to);
        cout << "移动圆盘 " << i << " 从 " << from << " 到 " << to << endl;
        f(i - 1, other, to, from);
    }
}

void hanoi(int n){
    if(n > 0){
        f(n, "左", "右", "中");
    }
}

int main(){
    int n = 3;
    hanoi(n);
    return 0;
}
