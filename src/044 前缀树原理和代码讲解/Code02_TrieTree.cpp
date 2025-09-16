#include <bits/stdc++.h>
using namespace std;

// 用固定数组实现前缀树，空间使用是静态的。推荐！
// 测试链接 : https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b

const int N = 150001;
int Tree[N][26], End[N], Pass[N], cnt;

void build(){
    cnt = 1;
}

void insert(string word){
    int cur = 1;
    Pass[cur]++;
    for(int i = 0, path; i < word.size(); i++){
        path = word[i] - 'a';
        if(Tree[cur][path] == 0){
            Tree[cur][path] = ++cnt;
        }
        cur = Tree[cur][path];
        Pass[cur]++;
    }
    End[cur]++;
}

int search(string word){
    int cur = 1;
    for(int i = 0, path; i < word.size(); i++){
        path = word[i] - 'a';
        if(Tree[cur][path] == 0){
            return 0;
        }
        cur = Tree[cur][path];
    }
    return End[cur];
}

int prefixNumber(string pre){
    int cur = 1;
    for(int i = 0, path; i < pre.size(); i++){
        path = pre[i] - 'a';
        if(Tree[cur][path] == 0){
            return 0;
        }
        cur = Tree[cur][path];
    }
    return Pass[cur];
}

void remove(string word){
    if(search(word) > 0){
        int cur = 1;
        Pass[cur]--;
        for(int i = 0, path; i < word.size(); i++){
            path = word[i] - 'a';
            if(--Pass[Tree[cur][path]] == 0){
                Tree[cur][path] = 0;
                return;
            }
            cur = Tree[cur][path];
        }
        End[cur]--;
    }
}

void clear(){
    for(int i = 1; i <= cnt; i++){
        memset(Tree[i], 0, sizeof(Tree[i]));
        End[i] = 0;
        Pass[i] = 0;
    }
}

void solve(){
    build();
    int m;
    cin >> m;
    while(m--){
        int op;
        string word;
        cin >> op >> word;
        if(op == 1){
            insert(word);
        }else if(op == 2){
            remove(word);
        }else if(op == 3){
            cout << (search(word) > 0 ? "YES" : "NO") << endl;
        }else{
            cout << prefixNumber(word) << endl;
        }
    }
    clear();
}

int main(){
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
