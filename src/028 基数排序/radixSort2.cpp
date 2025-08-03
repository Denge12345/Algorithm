#include <bits/stdc++.h>
using namespace std;

// 基数排序
// 测试链接 : https://leetcode.cn/problems/sort-an-array/

class Solution{
public:
    long long help[50009], cnts[50009], BASE = 10;
    int bits(long long num){
        int res = 0;
        while(num){
            num /= BASE;
            res++;
        }
        return res;
    }
    void radixSort(vector<int>& nums, int bit){
        int n = nums.size();
        for(long long offset = 1; bit > 0; offset *= BASE, bit--){
            memset(cnts, 0, sizeof(cnts));
            for(int i = 0; i < n; i++){
                cnts[(nums[i] / offset) % BASE]++;
            }
            for(int i = 1; i < BASE; i++){
                cnts[i] = cnts[i] + cnts[i - 1];
            }
            for(int i = n - 1; i >= 0; i--){
                help[--cnts[(nums[i] / offset) % BASE]] = nums[i];
            }
            for(int i = 0; i < n; i++){
                nums[i] = help[i];
            }
        }
    }
    vector<int> sortArray(vector<int>& nums){
        int n = nums.size();
        long long mina = INT_MAX, maxa = INT_MIN;
        for(int i = 0; i < n; i++){
            mina = min(mina, (long long)nums[i]);
        }
        for(int i = 0; i < n; i++){
            nums[i] -= mina;
            maxa = max(maxa, (long long)nums[i]);
        }
        radixSort(nums, bits(maxa));
        for(int i = 0; i < n; i++){
            nums[i] += mina;
        }
        return nums;
    }
};



void printArray(vector<int> nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {5, 2, 3, 1};
    vector<int> arr2 = {5, 1, 1, 2, 0, 0};
    Solution solution;
    printArray(solution.sortArray(arr1));
    printArray(solution.sortArray(arr2));
    return 0;
}
