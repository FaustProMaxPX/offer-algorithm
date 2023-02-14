#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序，
// 每一列都按照从上到下 非递减 的顺序排序。
// 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

/*
思路：
如果从矩阵的右上角出发，会发现它构成了一个二叉搜索树
*/


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) ++i;
            else --j;
        }
        return false;
    }

};

int main(int argc, char const *argv[]) {
    vector<vector<int>> m = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    // vector<vector<int>> m = {{}};
    Solution s;
    cout << s.findNumberIn2DArray(m, 5);
}