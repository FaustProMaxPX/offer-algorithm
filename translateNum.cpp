#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*/

/*
思路：
这是一道dp题，下面来找一下最优子结构。一个长度为1的字符串有1种翻译方式，而一个长度为2的字符串的翻译方式为第一个字母与第二个字母同时翻译，以及第一个字母和第二个字母分别翻译
那么一个长度为n的字符串的翻译方式有：当前字母单个翻译 -> 长度为n-1字符串的翻译个数 + 和前面一个字母连起来翻译 -> 长度为n-2字符串的翻译个数
因此这里设置状态转移方程为 dp[i] = dp[i-1]，如果倒数两个字母连起来可以被翻译，dp[i] = dp[i-1] + dp[i-2]
dp[i]表示截止位置在i的字符串可以被翻译的个数
*/

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        for (int i = 2; i <= s.length(); i++) {
            dp[i] = dp[i - 1];
            int t1 = s[i - 1] - '0';
            int t2 = s[i - 2] - '0';
            int t = t2 * 10 + t1;
            // 这里不允许10位为0
            if (t < 26 && t2 != 0) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.translateNum(12258);
    return 0;
}