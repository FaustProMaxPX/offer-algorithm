#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using namespace std;

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。
*/

/*
思路：
先找到所有符合条件的首个字母的坐标，然后将这些坐标作为起点，挨个调用深度优先搜索
为了确保一次查询不会出现重复路线，需要加上visit数组记录哪些节点访问过
查询过程：
1. 首先判断是否已经遍历完字符串，如果遍历完，代表已经找到了
2. 将当前节点设置为已经访问
3. 然后到周围四个节点中没有访问，且字符满足要求的部分继续深搜
4. 每次访问完毕都要将visited对应的位置设置为false
5. 4个方向中只要有一个满足，就返回true

正确性：
如果当前起点符合条件，最终会找到目标
如果不符合，半路就会被打回
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> vec;
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vec.push_back({i, j});
                }
            } 
        }
        for (pair<int, int> p : vec) {
            if (helper(board, word, p.first, p.second, 1, visited)) {
                return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int i, int j, int cur, vector<vector<bool>>& visited) {
        if (cur == word.size()) return true;
        visited[i][j] = true;
        int dic[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < 4; k++) {
            int ni = i + dic[k][0];
            int nj = j + dic[k][1];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && !visited[ni][nj] && word[cur] == board[ni][nj]) {
                bool res = helper(board, word, ni, nj, cur + 1, visited);
                if (res) {
                    visited[i][j] = false;
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> v {
        {'C','A','A'},
        {'A','A','A'},
        {'B','C','D'}
    };
    Solution s;
    cout << s.exist(v, "AAB");
    return 0;
}
