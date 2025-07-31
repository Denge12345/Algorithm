#include <bits/stdc++.h> 
using namespace std;

//set,map和priority_queue

int main(){
    map<int, string> mp;
    mp[5] = "这是5";
    mp[7] = "这是7";
    mp[1] = "这是1";
    mp[2] = "这是2";
    mp[3] = "这是3";
    mp[4] = "这是4";
    mp[8] = "这是8";
    cout << (mp.find(1) != mp.end()) << endl;
    cout << (mp.find(10) != mp.end()) << endl;
    cout << mp[4] << endl;
    mp[4] = "张三是4";
    cout << mp[4] << endl;
    mp.erase(4);
    cout << (mp.find(4) != mp.end()) << endl;
    cout << mp.begin()->first << endl;
    cout << mp.rbegin()->first << endl;
    auto it = mp.upper_bound(4);
    --it;
    cout << it->first << endl;
    cout << mp.lower_bound(4)->first << endl;

    cout << "===========" << endl;

    set<int> st;
    st.insert(3);
    st.insert(3);
    st.insert(4);
    st.insert(4);
    cout << "有序集合的大小: " << st.size() << endl;
    while(!st.empty()){
        //从前向尾部删除
        /*auto it = st.begin();
        cout << *it << endl;
        st.erase(it);*/
        //从尾部向前删除
        auto it = --st.end();
        cout << *it << endl;
        st.erase(it);
    }

    cout << "===========" << endl;

    //C++默认大根堆
    priority_queue<int> heap1;
    heap1.push(3);
    heap1.push(3);
    heap1.push(4);
    heap1.push(4);
    cout << "堆大小: " << heap1.size() << endl;
    while(!heap1.empty()){
        cout << heap1.top() << endl;
        heap1.pop();
    }

    cout << "===========" << endl;

    //定制小根堆
    priority_queue<int, vector<int>, greater<int>> heap2;
    heap2.push(3);
    heap2.push(3);
    heap2.push(4);
    heap2.push(4);
    cout << "堆大小: " << heap2.size() << endl;
    while(!heap2.empty()){
        cout << heap2.top() << endl;
        heap2.pop();
    }
    return 0;
}
