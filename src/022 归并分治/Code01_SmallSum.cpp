#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469

const int N = 1e5 + 9;
int a[N], help[N];

ll merge(int l, int m, int r){
    ll ans = 0;
    for(int i = l, j = m + 1, sum = 0; j <= r; j++){
        while(i <= m && a[i] <= a[j]){
            sum += a[i++];
        }
        ans += sum;
    }
    int hp = l;
    int pl = l;
    int pr = m + 1;
    while(pl <= m && pr <= r){
        help[hp++] = a[pl] <= a[pr] ? a[pl++] : a[pr++];
    }
    while(pl <= m){
        help[hp++] = a[pl++];
    }
    while(pr <= r){
        help[hp++] = a[pr++];
    }
    for(int i = l; i <= r; i++){
        a[i] = help[i];
    }
    return ans;
}

ll MergeSort(int l, int r){
    if(l == r){
        return 0;
    }
    int m = (l + r) / 2;
    return MergeSort(l, m) + MergeSort(m + 1, r) + merge(l, m, r);
}

int main(){
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << MergeSort(0, n - 1) << endl;
    return 0;
}
