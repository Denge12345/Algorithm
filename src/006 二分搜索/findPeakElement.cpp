#include <bits/stdc++.h>
using namespace std;

// 峰值元素是指其值严格大于左右相邻值的元素
// 给你一个整数数组 nums，已知任何两个相邻的值都不相等
// 找到峰值元素并返回其索引
// 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
// 你可以假设 nums[-1] = nums[n] = 无穷小
// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
// 测试链接 : https://leetcode.cn/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //先判断只有一个元素和两边元素的大小情况
        if (n == 1) {
            return 0;
        } else if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[n - 2] < nums[n - 1]) {
            return n - 1;
        } else {
            int l = 1, r = n - 1, ans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m - 1] > nums[m]) {
                    //左边元素比中间元素大,则说明是下降的
                    r = m - 1;
                } else if (nums[m + 1] > nums[m]) {
                    //右面元素比中间元素大,则说明是上升的
                    l = m + 1;
                } else {
                    //找到一个峰值(中间元素比左右都大),直接退出
                    ans = m;
                    break;
                }
            }
            return ans;
        }
    }
};

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] > nums[0]){
            return 0;
        }else if(nums[n - 1] > nums[n - 2]){
            return n - 1;
        }else{
            int l = 1, r = n - 1, ans = -1;
            while(l <= r){
                int m = (l + r) / 2;
                if(nums[m - 1] > nums[m]){
                    r = m - 1;
                }else if(nums[m + 1] > nums[m]){
                    l = m + 1;
                }else if(nums[m] > nums[m - 1] && nums[m] > nums[m + 1]){
                    ans = m;
                    break;
                }
            }
            return ans;
        }
    }
};
*/

int main(){
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    Solution solution;
    cout << solution.findPeakElement(nums1) << endl;
    cout << solution.findPeakElement(nums2) << endl;
}
