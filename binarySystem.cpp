#include <bits/stdc++.h>
using namespace std;

//负数 -> 负数的二进制
//负数 -> 负数的相反数的二进制 -> -1 -> 取反 -> 负数的二进制
// -6 -> 0110 -> 0101 -> 1010 -> -6(2) = 1010
//负数的二进制 -> 负数
//负数的二进制 -> 取反 -> +1 -> 负数的相反数的二进制 -> 负数
// 1011 -> 0100 -> 0101 -> 5(2) = 0101 -> -5

//打印32位二进制
void printBinary(int num){
	for(int i = 31; i >= 0; i--){
		cout << ((num & (1 << i)) == 0 ? 0 : 1);
	}
	cout << endl;
} 

bool returnTrue(){
	cout << "执行returnTrue函数" << endl;
	return true;
}

bool returnFalse(){
	cout << "执行returnFalse函数" << endl;
	return false;
}

int main(){
    //非负数
    cout << "===a===" << endl;
	int a = 78;
	cout << a << endl;
	printBinary(a);
	//负数
	cout << "===b===" << endl;
	int b = -6;
	cout << b << endl;
	printBinary(b);
	//直接写二进制
	cout << "===c===" << endl;
	int c = 0b1001110;
	cout << c << endl;
	printBinary(c); 
	//直接写十六进制
	cout << "===d===" << endl;
	int d = 0x4e;
	cout << d << endl;
	printBinary(d); 
	// ~ 相反数
	cout << "===e===" << endl;
	cout << a << endl;
	printBinary(a);
	printBinary(~a);
	int e = ~a + 1;
	cout << e << endl;
	printBinary(e);
	// int, long long的最小值取相反数,绝对值还是自己
	cout << "===f===" << endl;
	int f = INT_MIN;
	cout << f << endl;
	printBinary(f);
	cout << -f << endl;
	printBinary(-f);
	cout << ~f + 1 << endl;
	printBinary(~f + 1);
	// | & ^
	cout << "===g,h===" << endl;
	int g = 0b0001010;
	int h = 0b0001100;
	printBinary(g | h);
	printBinary(g & h);
	printBinary(g ^ h);
	// | || & &&
	cout << "===|,||,&,&&===" << endl;
	cout << "test1开始" << endl;
	bool test1 = returnTrue() | returnFalse();
	cout << "test1结果," << test1 << endl;
	cout << "test2开始" << endl;
	bool test2 = returnTrue() || returnFalse();
	cout << "test2结果," << test2 << endl;
	cout << "test3开始" << endl;
	bool test3 = returnTrue() & returnFalse();
	cout << "test3结果," << test3 << endl;
	cout << "test4开始" << endl;
	bool test4 = returnTrue() && returnFalse();
	cout << "test4结果," << test4 << endl;
	// || && 是逻辑运算符,两边只能用bool类型
	// || 只要遇到 true,后面的都不会执行
	// && 只要遇到 false,后面的都不会执行 
	// | & 是位运算符,两边的一定都会计算
	// <<
	cout << "=== i << ===" << endl;
	int i = 0b0011010;
	printBinary(i);
	printBinary(i << 1);
	printBinary(i << 2);
	printBinary(i << 3);
	// 非负数 >>
	cout << "=== i >> ===" << endl;
	printBinary(i);
	printBinary(i >> 2);
	// 负数 >>
	cout << "=== j >> ===" << endl;
	int j = 0b11110000000000000000000000000000;
	printBinary(j);
	printBinary(j >> 2);
	// 非负数 << i,等同于乘以2^i
	// 非负数 >> i,等同于除以2^i
	// 只有非负数符合这个特性
	cout << "=== k ===" << endl;
	int k = 10;
	cout << (k << 1) << endl;
	cout << (k << 2) << endl;
	cout << (k << 3) << endl;
	cout << (k >> 1) << endl;
	cout << (k >> 2) << endl;
	cout << (k >> 3) << endl;
    return 0;
}
