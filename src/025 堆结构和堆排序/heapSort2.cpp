#include <bits/stdc++.h>
using namespace std;

// 堆结构和堆排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/

class Solution {
public:
    void heapInsert(vector<int>& nums, int i){
        while(nums[i] > nums[(i - 1) / 2]){
            swap(nums[i], nums[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(vector<int>& nums, int i, int size){
        int l = 2 * i + 1;
        while(l < size){
            int best = l + 1 < size && nums[l + 1] > nums[l] ? l + 1 : l;
            best = nums[i] > nums[best] ? i : best;
            if(best == i){
                break;
            }
            swap(nums[i], nums[best]);
            i = best;
            l = 2 * i + 1;
        }
    }

    void heapSort1(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            heapInsert(nums, i);
        }
        int size = n;
        while(size > 1){
            swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
        }
    }

    void heapSort2(vector<int>& nums){
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            heapify(nums, i, n);
        }
        int size = n;
        while(size > 1){
            swap(nums[0], nums[--size]);
            heapify(nums, 0, size);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort1(nums);
        //heapSort2(nums);
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
