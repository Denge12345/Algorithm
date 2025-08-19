#include <bits/stdc++.h>
using namespace std;

// 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
// 测试链接 :
// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
    RandomizedCollection() {
        srand((unsigned int)time(0));
    }
    bool insert(int val) {
        arr.push_back(val);
        mp[val].insert(arr.size() - 1);
        return mp[val].size() == 1;
    }
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        int valAnyIndex = *mp[val].begin();
        int endValue = arr[arr.size() - 1];
        if(val == endValue){
            mp[val].erase(arr.size() - 1);
        }else{
            mp[endValue].insert(valAnyIndex);
            arr[valAnyIndex] = endValue;
            mp[endValue].erase(arr.size() - 1);
            mp[val].erase(valAnyIndex);
        }
        arr.pop_back();
        if(mp[val].empty()){
            mp.erase(val);
        }
        return true;
    }
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

void test(){
    RandomizedCollection* collection = new RandomizedCollection();// 初始化一个空的集合。
    cout << collection->insert(1) << endl;   // 返回 true，因为集合不包含 1。
                            // 将 1 插入到集合中。
    cout << collection->insert(1) << endl;   // 返回 false，因为集合包含 1。
                            // 将另一个 1 插入到集合中。集合现在包含 [1,1]。
    cout << collection->insert(2) << endl;   // 返回 true，因为集合不包含 2。
                            // 将 2 插入到集合中。集合现在包含 [1,1,2]。
    cout << collection->getRandom() << endl; // getRandom 应当:
                            // 有 2/3 的概率返回 1,
                            // 1/3 的概率返回 2。
    cout << collection->remove(1) << endl;   // 返回 true，因为集合包含 1。
                            // 从集合中移除 1。集合现在包含 [1,2]。
    cout << collection->getRandom() << endl; // getRandom 应该返回 1 或 2，两者的可能性相同。
}

int main(){
    test();
    return 0;
}
