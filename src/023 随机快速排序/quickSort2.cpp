#include <bits/stdc++.h>
using namespace std;

// 随机快速排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/

//直接提交如下类即可
class Solution {
public:
    int parition1(vector<int>& nums, int l, int r, int x){
        int a = l, xi = 0;
        for(int i = l; i <= r; i++){
            if(nums[i] <= x){
                swap(nums[a], nums[i]);
                if(nums[a] == x){
                    xi = a;
                }
                a++;
            }
        }
        swap(nums[xi], nums[a - 1]);
        return a - 1;
    }

    void quickSort1(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        int x = nums[l + rand() % (r - l + 1)];
        int m = parition1(nums, l, r, x);
        quickSort1(nums, l, m - 1);
        quickSort1(nums, m + 1, r);
    }

    int first, last;

    void partition2(vector<int>& nums, int l, int r, int x){
        first = l, last = r;
        int i = l;
        while(i <= last){
            if(nums[i] == x){
                i++;
            }else if(nums[i] < x){
                swap(nums[first++], nums[i++]);
            }else{
                swap(nums[last--], nums[i]);
            }
        }
    }

    void quickSort2(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        int x = nums[l + rand() % (r - l + 1)];
        partition2(nums, l, r, x);
        int left = first;
        int right = last;
        quickSort2(nums, l, left - 1);
        quickSort2(nums, right + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        //quickSort1(nums, 0, nums.size() - 1);
        quickSort2(nums, 0, nums.size() - 1);
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
