#include <bits/stdc++.h>
using namespace std;

// 不用任何判断语句和比较操作，返回两个数的最大值
// 测试链接 : https://www.nowcoder.com/practice/d2707eaf98124f1e8f1d9c18ad487f76

//0变1,1变0
int filp(int n){
    return n ^ 1;
}

//非负数返回1
//负数返回0
int sign(int n){
    return filp((n >> 31) & 1);
}

int getmax1(int a, int b){
    // a > b, c 为非负数, returnA = 1, returnB = 0
    // a < b, c 为负数, returnA = 0, returnB = 1
    int c = a - b;
    int returnA = sign(c);
    int returnB = filp(returnA);
    return a * returnA + b * returnB;
}

int getmax2(int a, int b){
    // c有可能溢出
    int c = a - b;
    // a的符号
    int sa = sign(a);
    // b的符号
    int sb = sign(b);
    // c的符号
    int sc = sign(c);
    // 判断AB符号是否不同,不同diffAB=1,相同diffAB=0
    int diffAB = sa ^ sb;
    // 判断AB符号是否相同,相同sameAB=1,不同sameAB=0
    int sameAB = filp(diffAB);
    // AB符号不同(diffAB = 1, sameAB = 0)
    // a > b, sa = 1, sb = 0, 返回a
    // a < b, sa = 0, sb = 1, 返回b
    // AB符号相同(diffAB = 0, sameAB = 1)
    // a > b, sc = 1, 返回a
    // a < b, sc = 0, 返回b
    int returnA = diffAB * sa + sameAB * sc;
    int returnB = filp(returnA);
    return a * returnA + b * returnB;
}

int main(){
    int a = INT_MIN;
    int b = INT_MAX;
    cout << getmax1(a, b) << endl;
    cout << getmax2(a, b) << endl;
    return 0;
}
