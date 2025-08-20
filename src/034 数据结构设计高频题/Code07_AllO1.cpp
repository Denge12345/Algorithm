#include <bits/stdc++.h>
using namespace std;

// 全O(1)的数据结构
// 测试链接 : https://leetcode.cn/problems/all-oone-data-structure/

class Bucket{
public:
    unordered_set<string> st;
    int cnt;
    Bucket* last;
    Bucket* next;
    Bucket(string s, int c){
        st.insert(s);
        cnt = c;
    }
};

class AllOne {
public:
    Bucket* head;
    Bucket* tail;
    unordered_map<string, Bucket*> mp;
    AllOne() {
        head = new Bucket("", 0);
        tail = new Bucket("", INT_MAX);
        head->next = tail;
        tail->last = head;
    }
    void inc(string key) {
        //如果不能找到就新建桶
        if(mp.find(key) == mp.end()){
            //如果head的下一个桶是1则直接放入
            //不是1就新建桶
            if(head->next->cnt == 1){
                mp[key] = head->next;
                head->next->st.insert(key);
            }else{
                Bucket* bucket = new Bucket(key, 1);
                mp[key] = bucket;
                add(head, bucket);
            }
        }else{
            Bucket* bucket = mp[key];
            //如果下一个桶是当前桶的个数+1则直接放入
            //否则就新建桶
            if(bucket->next->cnt == bucket->cnt + 1){
                mp[key] = bucket->next;
                bucket->next->st.insert(key);
            }else{
                Bucket* newBucket = new Bucket(key, bucket->cnt + 1);
                mp[key] = newBucket;
                add(bucket, newBucket);
            }
            //移除前一个桶中的key,如果桶为空就删除桶
            bucket->st.erase(key);
            if(bucket->st.empty()){
                remove(bucket);
            }
        }
    }
    void dec(string key) {
        Bucket* bucket = mp[key];
        //如果key所在桶的个数为1则直接删除桶
        if(bucket->cnt == 1){
            remove(bucket);
        }else{
            //如果key所在桶的前一个桶是所在桶的个数-1则直接放入
            //否则新建桶
            if(bucket->last->cnt == bucket->cnt - 1){
                mp[key] = bucket->last;
                bucket->last->st.insert(key);
            }else{
                Bucket* newBucket = new Bucket(key, bucket->cnt - 1);
                mp[key] = newBucket;
                add(bucket->last, newBucket);
            }
            //移除后一个桶中的key,如果桶为空就删除桶
            bucket->st.erase(key);
            if(bucket->st.empty()){
                remove(bucket);
            }
        }
    }
    string getMaxKey() {
        return *tail->last->st.begin();
    }
    string getMinKey() {
        return *head->next->st.begin();
    }
    void add(Bucket* cur, Bucket* pos){
        cur->next->last = pos;
        pos->next = cur->next;
        cur->next = pos;
        pos->last = cur;
    }
    void remove(Bucket* cur){
        cur->last->next = cur->next;
        cur->next->last = cur->last;
    }
};

void test(){
    AllOne* allOne = new AllOne();
    allOne->inc("hello");
    allOne->inc("hello");
    cout << allOne->getMaxKey() << endl; // 返回 "hello"
    cout << allOne->getMinKey() << endl; // 返回 "hello"
    allOne->inc("leet");
    cout << allOne->getMaxKey() << endl; // 返回 "hello"
    cout << allOne->getMinKey() << endl; // 返回 "leet"
}

int main(){
    test();
    return 0;
}
