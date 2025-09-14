#include <bits/stdc++.h>
using namespace std;

// 如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。
// 现在，给定两个正整数 L 和 R （以字符串形式表示），
// 返回包含在范围 [L, R] 中的超级回文数的数目。
// 1 <= len(L) <= 18
// 1 <= len(R) <= 18
// L 和 R 是表示 [1, 10^18) 范围的整数的字符串
//测试链接 : https://leetcode.cn/problems/super-palindromes/

class Solution1 {
public:
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        long long limit = static_cast<long long>(sqrt(r));
        long long seed = 1;
        long long num = 0;
        int ans = 0;
        do{
            num = evenEnlarge(seed);
            if(num <= limit && safeSquare(num) && check(num * num, l, r)){
                ans++;
            }
            num = oddEnlarge(seed);
            if(num <= limit && safeSquare(num) && check(num * num, l, r)){
                ans++;
            }
            seed++;
        } while(num < limit);
        return ans;
    }
    bool safeSquare(long long num) {
        return num <= static_cast<long long>(sqrt(numeric_limits<long long>::max()));
    }
    long long evenEnlarge(long long seed){
        long long ans = seed;
        while(seed){
            ans = ans * 10 + seed % 10;
            seed /= 10;
        }
        return ans;
    }
    long long oddEnlarge(long long seed){
        long long ans = seed;
        seed /= 10;
        while(seed){
            ans = ans * 10 + seed % 10;
            seed /= 10;
        }
        return ans;
    }
    bool check(long long ans, long long l, long long r){
        return ans >= l && ans <= r && isPalindrome(ans);
    }
    bool isPalindrome(long long num){
        long long offset = 1;
        while(num / offset >= 10){
            offset *= 10;
        }
        while(num){
            if(num / offset != num % 10){
                return false;
            }
            num = (num % offset) / 10;
            offset /= 100;
        }
        return true;
    }
};

class Solution2 {
public:
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        int i = 0;
        while(i < record.size() && record[i] < l){
            i++;
        }
        int j = record.size() - 1;
        while(j >= 0 && record[j] > r){
            j--;
        }
        return (j >= i) ? (j - i + 1) : 0;
    }
    vector<long long> record = {
        1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 
        14641ll, 40804ll, 44944ll, 1002001ll, 1234321ll, 
        4008004ll, 100020001ll, 102030201ll, 104060401ll, 
        121242121ll, 123454321ll, 125686521ll, 400080004ll, 
        404090404ll, 10000200001ll, 10221412201ll, 12102420121ll, 
        12345654321ll, 40000800004ll, 1000002000001ll, 1002003002001ll, 
        1004006004001ll, 1020304030201ll, 1022325232201ll, 
        1024348434201ll, 1210024200121ll, 1212225222121ll, 
        1214428244121ll, 1232346432321ll, 1234567654321ll, 
        4000008000004ll, 4004009004004ll, 100000020000001ll, 
        100220141022001ll, 102012040210201ll, 102234363432201ll, 
        121000242000121ll, 121242363242121ll, 123212464212321ll, 
        123456787654321ll, 400000080000004ll, 10000000200000001ll, 
        10002000300020001ll, 10004000600040001ll, 10020210401202001ll, 
        10022212521222001ll, 10024214841242001ll, 10201020402010201ll, 
        10203040504030201ll, 10205060806050201ll, 10221432623412201ll, 
        10223454745432201ll, 12100002420000121ll, 12102202520220121ll, 
        12104402820440121ll, 12122232623222121ll, 12124434743442121ll, 
        12321024642012321ll, 12323244744232321ll, 12343456865434321ll, 
        12345678987654321ll, 40000000800000004ll, 40004000900040004ll, 
        1000000002000000001ll, 1000220014100220001ll, 1002003004003002001ll, 
        1002223236323222001ll, 1020100204020010201ll, 1020322416142230201ll, 
        1022123226223212201ll, 1022345658565432201ll, 1210000024200000121ll, 
        1210242036302420121ll, 1212203226223022121ll, 1212445458545442121ll, 
        1232100246420012321ll, 1232344458544432321ll, 1234323468643234321ll, 
        4000000008000000004ll
    };
};

class Collection{
public:
    vector<long long> collect(){
        long long l = 1;
        long long r = LLONG_MAX;
        long long limit = static_cast<long long>(sqrtl(r));
        long long seed = 1;
        long long enlarge = 0;
        vector<long long> ans;
        do{
            enlarge = evenEnlarge(seed);
            if(enlarge <= limit && safeSquare(enlarge) && check(enlarge * enlarge, l, r)){
                ans.push_back(enlarge * enlarge);
            }
            enlarge = oddEnlarge(seed);
            if(enlarge <= limit && safeSquare(enlarge) && check(enlarge* enlarge, l, r)){
                ans.push_back(enlarge* enlarge);
            }
            seed++;
        }while(enlarge < limit);
        sort(ans.begin(), ans.end());
        return ans;
    }
    bool safeSquare(long long num) {
        return num <= static_cast<long long>(sqrt(numeric_limits<long long>::max()));
    }
    long long evenEnlarge(long long seed){
        long long ans = seed;
        while(seed){
            ans = ans * 10 + seed % 10;
            seed /= 10;
        }
        return ans;
    }
    long long oddEnlarge(long long seed){
        long long ans = seed;
        seed /= 10;
        while(seed){
            ans = ans * 10 + seed % 10;
            seed /= 10;
        }
        return ans;
    }
    bool check(long long num, long long l, long long r){
        return num >= l && num <= r && isPalindrome(num);
    }
    bool isPalindrome(long long num){
        long long offset = 1;
        while(num / offset >= 10){
            offset *= 10;
        }
        while(num){
            if(num / offset != num % 10){
                return false;
            }
            num = (num % offset) / 10;
            offset /= 100;
        }
        return true;
    }
};

int main(){
    Collection collection;
    vector<long long> ans = collection.collect();
    for(long long p : ans){
        cout << p << "ll, ";
    }
    cout << "size : " << ans.size() << endl;
    return 0;
}
