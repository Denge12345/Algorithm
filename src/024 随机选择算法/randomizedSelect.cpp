#include <bits/stdc++.h>
using namespace std;

// 无序数组中第K大的元素
// 测试链接 : https://leetcode.cn/problems/kth-largest-element-in-an-array/

// 直接提交如下类即可
class Solution {
public:
    int first, last;
    void partition(vector<int>& nums, int l, int r, int x){
        first = l;
        last = r;
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

    int randomizedSelect(vector<int>& nums, int i){
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        while(l <= r){
            partition(nums, l, r, nums[l + rand() % (r - l + 1)]);
            if(i < first){
                r = first - 1;
            }else if(i > last){
                l = last + 1;
            }else{
                ans = nums[i];
                break;
            }
        }
        return ans;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return randomizedSelect(nums, nums.size() - k);        
    }
};

int main(){
    srand((unsigned int)time(NULL));
    vector<int> arr1 = {3, 2, 1, 5, 6, 4};
    vector<int> arr2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution solution;
    cout << solution.findKthLargest(arr1, 2) << endl;
    cout << solution.findKthLargest(arr2, 4) << endl;
    return 0;
}
