#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

/*
思路：
最优子结构：如果我们知道了某一格的上方和左侧的最大值，那么就可以推算出这一格的最大值
状态转移方程：dp[i][j]指到达棋盘第i行第j列时的最大价值。dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + vals[i][j]
*/

/*
优化：我们可以发现dp[i][j]的值仅与左侧和上方的值有关，因此i-2之前以及j-2之前的值没有必要保存
我们可以将dp数组更换为一维数组，它的大小就是矩阵的列数。此时dp[j] = max(dp[j-1], dp[j]) + vals[i][j]
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int dp[grid.size()][grid[0].size()];
        dp[0][0] = grid[0][0];
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i <  row; i++) {
            vector<int> vec = grid[i];
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                }
            }
        }
        return dp[row-1][col-1];
    }

    int maxValue0(vector<vector<int>>& grid) {
        int dp[grid[0].size()];
        dp[0] = grid[0][0];
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i <  row; i++) {
            vector<int> vec = grid[i];
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[j] = dp[j-1] + grid[i][j];
                } else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    dp[j] = max(dp[j-1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[col-1];
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> v {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution s;
    cout << s.maxValue0(v);

    return 0;
}