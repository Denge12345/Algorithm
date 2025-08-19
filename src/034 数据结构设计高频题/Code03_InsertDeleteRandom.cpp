#include <bits/stdc++.h>
using namespace std;

// 插入、删除和获取随机元素O(1)时间的结构
// 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1/
// 直接提交如下方法即可
class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet() {
        srand((unsigned int)time(0));
    }
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
        return false;
    }
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int valIndex = mp[val];
            int endValue = arr[arr.size() - 1];
            mp[endValue] = valIndex;
            arr[valIndex] = endValue;
            mp.erase(val);
            arr.pop_back();
            /*arr[mp[val]] = arr[arr.size() - 1];
            mp[arr[arr.size() - 1]] = mp[val];
            mp.erase(val);
            arr.resize(arr.size() - 1);*/
            return true;
        }
        return false;
    }
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

void test(){
    RandomizedSet* randomizedSet = new RandomizedSet();
    cout << randomizedSet->insert(1) << endl; // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    cout << randomizedSet->remove(2) << endl; // 返回 false ，表示集合中不存在 2 。
    cout << randomizedSet->insert(2) << endl; // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    cout << randomizedSet->getRandom() << endl; // getRandom 应随机返回 1 或 2 。
    cout << randomizedSet->remove(1) << endl; // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    cout << randomizedSet->insert(2) << endl; // 2 已在集合中，所以返回 false 。
    cout << randomizedSet->getRandom() << endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
}

int main(){
    test();
    return 0;
}
