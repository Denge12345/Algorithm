#include <bits/stdc++.h>
using namespace std;

//自定义比较函数,lambda表达式和字典序

class Employee{
    public:
    Employee() : company(0), age(0) {}
    Employee(int c, int a) : company(c), age(a) {}
    //重载 < 运算符 (自定义排序会用到)
    //与类外实现自定义排序保留其一
    //使用类外自定义排序函数需要在sort中填入函数名
    /*bool operator < (const Employee& u) const {
        return age < u.age;
    }*/
    //set的自定义排序函数(使用时需要有默认构造函数)
    bool operator ()(const Employee& u, const Employee& v){
        return u.company != v.company ? u.company < v.company : u.age < v.age;  
    }
    int company;
    int age;
};

//自定义排序函数
bool cmp(const Employee& u, const Employee& v){
    //如果返回true则u排在v前面
    //如果返回false则v排在u前面
    return u.company < v.company;
}

int main(){
    Employee s1(2, 27);
    Employee s2(1, 60);
    Employee s3(4, 19);
    Employee s4(3, 23);
    Employee s5(1, 35);
    Employee s6(3, 55);
    Employee arr[6] = {s1, s2, s3, s4, s5, s6};

    //使用自定义排序函数
    sort(arr, arr + 6, cmp);
    for(Employee e : arr){
        cout << e.company << ", " << e.age << endl;
    }

    cout << "=====" << endl;
    //使用lambda表达式
    //谁年龄大谁排前面
    sort(arr, arr + 6, [](const Employee& u, const Employee& v){return u.age > v.age;});
    for(Employee e : arr){
        cout << e.company << ", " << e.age << endl;
    }

    cout << "=====" << endl;
    //如果公司编号不相等,则公司编号小的排在前面,若相等,则年龄小的排在前面
    sort(arr, arr + 6, [](const Employee& u, const Employee& v){return u.company != v.company ? u.company < v.company : u.age < v.age;});
    for(Employee e : arr){
        cout << e.company << ", " << e.age << endl;
    }

    cout << "=====" << endl;

    set<Employee, Employee> st1;
    for(Employee e : arr){
        st1.insert(e);
    }
    cout << st1.size() << endl;
    //会去重
    st1.insert(Employee(2, 27));
    cout << st1.size() << endl;
    //c++无法像java一样像在创建对象的时候直接规定如何去重和排序规则
    //即使可以用vector辅助排序,但也不能将排序后的结果存入到set中,因为会打乱排序规则
    //只能先进行去重,然后将结果放到vector中进行排序
    cout << "===" << endl;

    char *str1 = "abcde";
    char *str2 = "ks";
    //如果两个字符串的ASCII值一样,返回0
    //如果第一个大于第二个,返回大于0的值
    //如果第一个小于第二个,返回小于0的值
    cout << strcmp(str1, str2) << endl;
    cout << strcmp(str2, str1) << endl;
    return 0;
}
