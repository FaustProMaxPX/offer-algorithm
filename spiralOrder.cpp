#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

/*
思路：
每完成一圈遍历，就向内部缩一层，遍历的起点就向内部+1
使用一个变量来存储层级，首先是在顶端横向遍历，起点为level，直到横向数据个数-level [level][level] -> [level][matrix[0].size() - level - 1]
接着在最右端向下遍历，起点是矩阵横向大小减已经遍历的层数-1，直到level [level + 1][matrix[0].size() - level - 1] -> [matrix.size() - 1 - level][matrix[0].size() - level - 1]
然后是底端从右向左遍历，起点是[martix.size() - level - 1][martix[0].size() - level - 2]直到[martix.size() - level - 1][level]
接着是最左端从下往上遍历起点是[matrix.size() - 1 - level - 1][level]直到[level + 1][level]
当level大于matrix.size()/2时结束（行数为奇数），如果为偶数，level > row/2-1时终止
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        vector<int> ret;
        int level = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        // 这里要注意，奇数行和偶数行的终止条件不同
        int limit = (row & 1) ? row / 2 : row / 2 - 1;
        while (level <= limit) {
            for (int j = level; j < col - level; j++) ret.push_back(matrix[level][j]);
            // 继续移动的前提是，上一步的地点是合法的
            if (col - level <= level) break;
            for (int i = level + 1; i < row - level; i++) ret.push_back(matrix[i][col - level - 1]);
            if (row - level <= level + 1) break;
            for (int j = col - level - 2; j >= level; j--) ret.push_back(matrix[row - level - 1][j]);
            if (col - level - 2 < level) break;
            for (int i = row - level - 2; i > level; i--) ret.push_back(matrix[i][level]);
            ++level;
        }
        return ret;
    }
};

int main(int argc, const char** argv) {
    vector<vector<int>> v {{1,2,3,4}, {5,6,7,8},{9,10,11,12}};
    Solution s;
    s.spiralOrder(v);
    return 0;
}