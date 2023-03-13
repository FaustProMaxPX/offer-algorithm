#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

/*
思路：
最优子结构：如果我们知道了长度为a的串和长度为b的正则匹配式可以匹配，那么就可以求解出长度为a+1与b+1的匹配情况
dp[i][j]含义：s[:i]与p[:j]能否匹配，注意dp[i][j]最后一位分别是s的第i-1位和p的j-1位
下面分情况讨论：
如果p[j-1] != '*'，那么只要比较s[i-1]和p[j-1]即可，如果他们相等且dp[i-1][j-1] == true dp[i-1][j-1] = true
如果p[j-1] == '*'，那么以下情况有一个成立，dp[i][j]就为true
1. dp[i][j-2] 将字符组合p[j-2] * 看作出现0次
2. dp[i-1][j] && s[i-1] == p[j-2] 让字符p[j-2]多出现一次
3. dp[i-1][j] && p[j-2] == '.'

初始化：
1. dp[0][0] = true
2. dp[0][j] = dp[0][j-2] && p[j-1] == '*'
*/

bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.length() + 1, vector<bool> (p.length() + 1, false));
    dp[0][0] = true;
    for (int j = 2; j <= p.length(); j += 2) dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= p.length(); j++) {
            if (p[j - 1] == '*') {
                if (dp[i][j - 2]) dp[i][j] = true;
                if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true;
                if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;
            } else {
                if (s[i - 1] == p[j - 1] && dp[i - 1][j - 1]) dp[i][j] = true;
                else if (p[j - 1] == '.' && dp[i - 1][j - 1]) dp[i][j] = true;
            }
        }
    }
    return dp[s.length()][p.length()];
}

int main(int argc, char const *argv[]) {
    cout << isMatch("ab", ".*");
    return 0;
}