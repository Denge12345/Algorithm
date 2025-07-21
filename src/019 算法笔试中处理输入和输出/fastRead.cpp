#include <bits/stdc++.h>
using namespace std;

//测试链接: https://www.luogu.com.cn/problem/P10815

//使用cin和cout
//超时1个 不开O2优化,通过的样例最慢2.45s
void testCinAndCout(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        ans += num;
    }
    cout << ans << endl;
}

//取消输入输出流
//超时1个 不开O2优化,通过的样例最慢648ms
void testCancelIOStream(){
    //取消输入输出流后最好不要使用scanf和printf
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        ans += num;
    }
    cout << ans << endl;
}

//使用scanf和printf
//超时1个 不开O2优化,通过的样例最慢952ms
void testScanfAndPrintf(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int num; scanf("%d", &num);
        ans += num;
    }
    printf("%d", ans);
}

//自己写快读
//超时1个 不开O2优化,通过的样例最慢281ms
inline int read1(){
    int s = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        //是否读到了负号(是否是负数)
        if(ch == '-') w *= -1;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9'){
        //使用位运算可能会比较快一点
        //s = s * 10 + ch -'0';
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
    }
    return s * w;
}

void testGetChar(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int num; num = read1();
        ans += num;
    }
    printf("%d", ans);
}

//使用fread和自己写快读
//通过全部测试样例 不开O2优化,通过的样例最慢1.41s
//buf表示输入缓冲区,p1表示当前读取位置,p2表示缓冲区有效数据结束位置
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline char gc(){
    //缓冲区是否读完
    if(p1 == p2){
        //重新填充缓冲区
        //从标准输入(stdin)读取最多1<<21字节数据到缓冲区buf
        p2 = buf + fread(buf, 1, 1 << 21, stdin);
        p1 = buf;
    }
    return *p1++;
}

inline int read2(){
    int s = 0, w = 1;
    char ch = gc();
    while(ch < '0' || ch > '9'){
        //是否读到了负号(是否是负数)
        if(ch == '-') w *= -1;
        ch = gc();
    }
    while('0' <= ch && ch <= '9'){
        //使用位运算可能会比较快一点
        //s = s * 10 + ch -'0';
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = gc();
    }
    return s * w;
}

void testFread(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int num; num = read2();
        ans += num;
    }
    cout << ans;
}

//注意提交时要只保留一个取消注释的函数
int main(){
    //testCinAndCout();
    //testCancelIOStream();
    //testScanfAndPrintf();
    //testGetChar();
    testFread();
    return 0;
}
