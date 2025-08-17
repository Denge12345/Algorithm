#include <bits/stdc++.h>
using namespace std;

// setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967

int main(){
    int n;
    cin >> n;
    //设置时间戳
    int setAllValue = 0, setAllTime = -1, cnt = 0;
    unordered_map<int, vector<int>> mp;
    //mp -> [键, {键值, 时间戳}]
    while(n--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            if(mp.find(x) != mp.end()){
                mp[x][0] = y;
                mp[x][1] = cnt++;
            }else{
                mp[x] = {y, cnt++};
            }
        }else if(op == 2){
            int x;
            cin >> x;
            if(mp.find(x) != mp.end()){
                if(mp[x][1] > setAllTime){
                    cout << mp[x][0] << endl;
                }else{
                    // <= 进行setAll操作的时间的数值都输出setAllValue
                    cout << setAllValue << endl;
                }
            }else{
                cout << -1 << endl;
            }
        }else{
            int x;
            cin >> x;
            setAllValue = x;
            setAllTime = cnt++;
        }
    }
    return 0;
}
