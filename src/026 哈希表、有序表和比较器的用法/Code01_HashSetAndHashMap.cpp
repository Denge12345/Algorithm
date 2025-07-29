#include <bits/stdc++.h>
using namespace std;

//unordered_set和unordered_map

class Student{
    public:
    Student() : age(0), name("") {}
    Student(int a, string b) : age(a), name(b) {}
    //重载==
    bool operator == (const Student& s) const {
		return age == s.age && name == s.name;
	}
    //自定义哈希函数
    //size_t 在32位下相当于 unsigned int
    //size_t 在64位下相当于 unsigned long long
	size_t operator()(const Student& s) const {
        //计算age的哈希值并让其左移一位
        //计算name的哈希值
        //返回两个数值异或后的结果
        return hash<string>()(s.name) ^ (hash<int>()(s.age) << 1);
    }
    int age;
    string name;
};

int main(){
    string str1 = "Hello";
    string str2 = "Hello";
    // 因为两个指针指向的是不同的内存地址
    // 即使存储的值相同，两个指针也不相同
    // 所以返回false
    cout << (&str1 == &str2) << endl;
    // 进行解引用，值相同，返回true
    cout << (str1 == str2) << endl;

    cout << "===========" << endl;

    unordered_set<string> st;
    st.insert(str1);
    cout << (st.find("Hello") != st.end()) << endl;
    cout << (st.find(str2) != st.end()) << endl;
    st.insert(str2);
    cout << st.size() << endl;
    st.erase(str1);
    st.clear();
    cout << st.empty() << endl;

    cout << "===========" << endl;

    unordered_map<string, string> mp1;
    mp1[str1] = "World";
    cout << mp1["Hello"] << endl;
    cout << mp1[str2] << endl;
    cout << (mp1.find(str2) != mp1.end()) << endl;
    cout << (mp1.find("你好") != mp1.end()) << endl;
    mp1.erase("Hello");
    cout << mp1.size() << endl;
    mp1.clear();
    cout << mp1.empty() << endl;

    cout << "===========" << endl;
    unordered_map<int, int> mp2;
    mp2[56] = 7285;
    mp2[34] = 3671263;
    mp2[17] = 716311;
    mp2[24] = 1263161;
    int arr[100] = {0};
    arr[56] = 7285;
    arr[34] = 3671263;
    arr[17] = 716311;
    arr[24] = 1263161;
    cout << "在笔试场合中哈希表往往会被数组替代" << endl;

    cout << "===========" << endl;

    Student s1(17, "张三");
    Student s2(17, "张三");
    unordered_map<Student, string, Student> mp3;
    mp3[s1] = "这是张三";
    cout << (mp3.find(s1) != mp3.end()) << endl;
    cout << (mp3.find(s2) != mp3.end()) << endl;
    mp3[s2] = "这是另一个张三";
    cout << mp3.size() << endl;
    cout << mp3[s1] << endl;
    cout << mp3[s2] << endl;
    return 0;
}
