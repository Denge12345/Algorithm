#include <bits/stdc++.h>
using namespace std;

// 归并排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/

//直接提交以下类即可
class Solution {
public:
    int help[50009];
    void merge(vector<int>& nums, int l, int m, int r){
        int hp = l;
        int pl = l;
        int pr = m + 1;
        while(pl <= m && pr <= r){
            help[hp++] = nums[pl] <= nums[pr] ? nums[pl++] : nums[pr++];
        }
        while(pl <= m){
            help[hp++] = nums[pl++];
        }
        while(pr <= r){
            help[hp++] = nums[pr++];
        }
        for(int i = l; i <= r; i++){
            nums[i] = help[i];
        }
    }
    //递归实现归并排序
    void MergeSort1(vector<int>& nums, int l, int r){
        if(l == r){
            return;
        }
        int m = (l + r) / 2;
        MergeSort1(nums, l, m);
        MergeSort1(nums, m + 1, r);
        merge(nums, l, m, r);
    }
    //迭代实现归并排序
    void MergeSort2(vector<int>& nums, int n){
        for(int l, m, r, step = 1; step < n; step *= 2){
            l = 0;
            while(l < n){
                m = l + step - 1;
                if(m + 1 > n){
                    break;
                }
                r = min(l + 2 * step - 1, n - 1);
                merge(nums, l, m, r);
                l = r + 1;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        MergeSort1(nums, 0, nums.size() - 1);
        //MergeSort2(nums, nums.size());
        return nums;
    }
};

void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums1 = {5, 2, 3, 1};
    vector<int> nums2 = {5, 1, 1, 2, 0, 0};
    Solution solution;
    printArray(solution.sortArray(nums1));
    printArray(solution.sortArray(nums2));
    return 0;
}
