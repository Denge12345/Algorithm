#include <bits/stdc++.h>
using namespace std;

// 测试链接 : https://leetcode.cn/problems/reverse-pairs/
// 直接提交如下类即可
class Solution {
public:
    int help[50009];
    int merge(vector<int>& arr, int l, int m, int r){
        int ans = 0;
        for(int i = l, j = m + 1; i <= m; i++){
            while(j <= r && 1ll * arr[i] > 1ll * 2 * arr[j]){
                j++;
            }
            ans += j - m - 1;
        }
        int hp = l;
        int pl = l;
        int pr = m + 1;
        while(pl <= m && pr <= r){
            help[hp++] = arr[pl] <= arr[pr] ? arr[pl++] : arr[pr++];
        }
        while(pl <= m){
            help[hp++] = arr[pl++];
        }
        while(pr <= r){
            help[hp++] = arr[pr++];
        }
        for(int i = l; i <= r; i++){
            arr[i] = help[i];
        }
        return ans;
    }
    int mergeSort(vector<int>& arr, int l, int r){
        if(l == r){
            return 0;
        }
        int m = (l + r) / 2;
        return mergeSort(arr, l, m) + mergeSort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main(){
    vector<int> arr1 = {1, 3, 2, 3, 1};
    vector<int> arr2 = {2, 4, 3, 5, 1};
    Solution solution;
    cout << solution.reversePairs(arr1) << endl;
    cout << solution.reversePairs(arr2) << endl;
    return 0;
}
