#include <bits/stdc++.h>
using namespace std;

// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢

string f(int rest, string cur){
    string enemy = cur == "A" ? "B" : "A";
    if(rest < 5){
        return (rest == 0 || rest == 2) ? enemy : cur;
    }
    int pick = 1;
    while(pick <= rest){
        if(f(rest - pick, enemy) == cur){
            return cur;
        }
        pick *= 4;
    }
    return enemy;
}

string win1(int n){
    return f(n, "A");
}

string win2(int n){
    if(n % 5 == 0 || n % 5 == 2){
        return "B";
    }else{
        return "A";
    }
}

int main(){
    for(int i = 0; i <= 50; i++){
        cout << i << " : " << win1(i) << endl;
    }
    return 0;
}
