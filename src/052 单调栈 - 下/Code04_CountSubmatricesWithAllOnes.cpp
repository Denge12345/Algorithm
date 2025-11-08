#include <bits/stdc++.h>
using namespace std;

// 统计全1子矩形的数量
// 给你一个 m * n 的矩阵 mat，其中只有0和1两种值
// 请你返回有多少个 子矩形 的元素全部都是1
// 测试链接 : https://leetcode.cn/problems/count-submatrices-with-all-ones/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> heights(m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
            }
            ans += countFromBottom(heights);
        }
        return ans;
    }
    // 比如
	//              1
	//              1
	//              1         1
	//    1         1         1
	//    1         1         1
	//    1         1         1
	//             
	//    3  ....   6   ....  8
	//   left      cur        i
	// 如上图，假设6位置从栈中弹出，6位置的高度为6(上面6个1)
	// 6位置的左边、离6位置最近、且小于高度6的是3位置(left)，3位置的高度是3
	// 6位置的右边、离6位置最近、且小于高度6的是8位置(i)，8位置的高度是4
	// 此时我们求什么？
	// 1) 求在4~7范围上必须以高度6作为高的矩形有几个？
	// 2) 求在4~7范围上必须以高度5作为高的矩形有几个？
	// 也就是说，<=4的高度一律不求，>6的高度一律不求！
	// 其他位置也会从栈里弹出，等其他位置弹出的时候去求！
	// 那么在4~7范围上必须以高度6作为高的矩形有几个？如下：
	// 4..4  4..5  4..6  4..7
	// 5..5  5..6  5..7
	// 6..6  6..7
	// 7..7
	// 10个！什么公式？
	// 4...7范围的长度为4，那么数量就是 : 4*5/2
	// 同理在4~7范围上，必须以高度5作为高的矩形也是这么多
	// 所以cur从栈里弹出时产生的数量 : 
	// (cur位置的高度-Max{left位置的高度,i位置的高度}) * ((i-left-1)*(i-left)/2)
    int countFromBottom(vector<int>& heights){
        int n = heights.size(), r = 0;
        vector<int> stk(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(r > 0 && heights[stk[r - 1]] >= heights[i]){
                int cur = stk[--r];
                if(heights[cur] > heights[i]){
                    // 只有height[cur] > height[i]才结算
                    // 如果是因为height[cur]==height[i]导致cur位置从栈中弹出
                    // 那么不结算！等i位置弹出的时候再说！
                    // 上一节课讲了很多这种相等时候的处理，比如"柱状图中最大的矩形"问题
                    int left = r > 0 ? stk[r - 1] : -1;
                    int len = i - left - 1;
                    int bottom = max(left == -1 ? 0 : heights[left], heights[i]);
                    ans += (heights[cur] - bottom) * len * (len + 1) / 2;
                }
            }
            stk[r++] = i;
        }
        while(r > 0){
            int cur = stk[--r];
            int left = r > 0 ? stk[r - 1] : -1;
            int len = n - left - 1;
            int down = left == -1 ? 0 : heights[left];
            ans += (heights[cur] - down) * len * (len + 1) / 2;
        }
        return ans;
    }
};

int main(){

    return 0;
}
