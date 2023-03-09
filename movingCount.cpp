#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <cmath>

using namespace std;

// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，
// 它每次可以向左、右、上、下移动一格（不能移动到方格外），
// 也不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，
// 因为3+5+3+7=18。但它不能进入方格 [35, 38]，
// 因为3+5+3+8=19。请问该机器人能够到达多少个格子？

/*
思路：
深搜算法，初始化一个visited数组用于记录哪些节点被访问过
从[0,0]开始，判断当前位置是否满足条件，如果满足，结果+1
然后向上下左右没有访问过的节点移动
如果不满足，直接返回
*/

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return helper(m, n, k, 0, 0, visited);
    }

    int helper(int m, int n, int k, int i, int j, vector<vector<bool>>& visited) {
        
        if (!check(i, j, k)) {
            return 0;
        }
        int res = 1;
        int dic[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        visited[i][j] = true;
        for (int z = 0; z < 4; z++) {
            int ni = i + dic[z][0];
            int nj = j + dic[z][1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                res += helper(m, n, k, ni, nj, visited);
            }
        }
        return res;
    }

    bool check(int i, int j, int k) {
        string t1 = to_string(i);
        string t2 = to_string(j);
        int tt1 = 0;
        int tt2 = 0;
        for (int z = t1.size() - 1; z >= 0; z--) {
            int p = t1.size() - 1 - z;
            tt1 += (t1[z] - '0');
        }
        for (int z = t2.size() - 1; z >= 0; z--) {
            int p = t2.size() - 1 - z;
            tt2 += (t2[z] - '0');
        }
        return tt1 + tt2 <= k;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    cout << s.movingCount(16, 8, 4);
    return 0;
}
