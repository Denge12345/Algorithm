#include <bits/stdc++.h>
using namespace std;

// 测试链接 : https://leetcode.cn/problems/implement-trie-ii-prefix-tree/

class TrieNode1 {
public:
    int pass;
    int end;
    TrieNode1* nexts[26];
    TrieNode1(){
        pass = 0;
        end = 0;
        for(int i = 0; i < 26; i++){
            nexts[i] = nullptr;
        }
    }
};

class Trie1 {
public:
    TrieNode1* root;
    Trie(){
        root = new TireNode();
    }
    void insert(string& word){
        TrieNode1* node = root;
        node->pass++;
        for(int i = 0, path; i < word.size(); i++){
            path = word[i] - 'a';
            if(node->nexts[path] == nullptr){
                node->nexts[path] = new TrieNode1();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end++;
    }
    int countWordsEqualTo(string& word){
        TrieNode1* node = root;
        for(int i = 0, path; i < word.size(); i++){
            path = word[i] - 'a';
            if(node->nexts[path] == nullptr){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->end;
    }
    void erase(string& word){
        if(countWordsEqualTo(word) > 0){
            TrieNode1* node = root;
            node->pass--;
            for(int i = 0, path; i < word.size(); i++){
                path = word[i] - 'a';
                if(--node->nexts[path]->pass == 0){
                    //delete node->nexts[path];
                    node->nexts[path] = nullptr;
                    return;
                }
                node = node->nexts[path];
            }
            node->end--;
        }
    }
    int countWordsStartingWith(string& pre){
        TrieNode1* node = root;
        for(int i = 0, path; i < pre.size(); i++){
            path = pre[i] - 'a';
            if(node->nexts[path] == nullptr){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->pass;
    }
};

class TrieNode2 {
public:
    int pass;
    int end;
    unordered_map<int, TrieNode2*> nexts;
    TrieNode2(){
        pass = 0;
        end = 0;
    }
};

class Tire2 {
    public:
    TrieNode2* root;
    Trie2(){
        root = new TrieNode2();
    }
    void insert(string& word){
        TrieNode2* node = root;
        node->pass++;
        for(int i = 0, path; i < word.size(); i++){
            path = word[i];
            if(node->nexts.find(path) == node->nexts.end()){
                node->nexts[path] = new TrieNode2();
            }
            node = node->nexts[path];
            node->pass++;
        }
        node->end++;
    }
    int countWordsEqualTo(string& word){
        TrieNode2* node = root;
        for(int i = 0, path; i < word.size(); i++){
            path = word[i];
            if(node->nexts.find(path) == node->nexts.end()){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->end;
    }
    void erase(string& word){
        if(countWordsEqualTo(word) > 0){
            TrieNode2* node = root;
            node->pass--;
            for(int i = 0, path; i < word.size(); i++){
                path = word[i];
                if(--node->nexts[path]->pass == 0){
                    node->nexts.erase(path);
                    delete node->nexts[path];
                    return;
                }
                node = node->nexts[path];
            }
            node->end--;
        }
    }
    int countWordsStartingWith(string& pre){
        TrieNode2* node = root;
        for(int i = 0, path; i < pre.size(); i++){
            path = pre[i];
            if(node->nexts.find(path) == node->nexts.end()){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->pass;
    }
};

int main(){

    return 0;
}
