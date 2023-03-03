#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;

// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

/*
思路：（不是自己写（（（  ）
最优子结构：如果我们已知以第n-1个字符结尾的最小无重复的字符串，那么就可以退出以第n个字符结尾的最小无重复的字符串
首先定义dp[i]为以第i个字符为结尾的无重复字符的字符串的长度。（重点）
如果第i个字符未曾出现，那么dp[i] = dp[i-1] + 1
如果第i个字符已经出现过，就要分情况讨论：
1. 重复字符出现在目前最长的不重复子串中，此时表现在代码里就是当前字符与上一个重复字符的距离不超过不重复子串长度，此时dp[i] = d(d即重复的两个字符的距离)
2. 重复字符没出现在目前最长的不重复子串中，则dp[i] = dp[i-1] + 1

代码描述：
定义一个长度为n+1的dp数组
如果s长度为0，返回0
定义一个哈希表，记录对应字符最后一次出现在字符串中的下标
循环遍历字符串，直至循环变量大于dp长度：
    如果当前字符没出现过，dp[i] = dp[i-1] + 1
    如果当前字符出现过：
        d = i - 1 - ch[s[i - 1] - 'a']
        if d <= dp[i-1] -> dp[i] = d
        else dp[i] = dp[i-1] + 1
    更新字符出现位置 ch[s[i - 1] - 'a'] = i - 1
    最后返回dp数组中的最大值即可
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 注意一下dp下标与字符串下标的对应问题
        // 比如这一题里dp[i]代表访问到s[i-1]
        int dp[s.length() + 1];
        unordered_map<char, int> map;
        if (s.length() == 0) return 0;
        dp[0] = 0;
        int maxn = 0;
        for (size_t i = 1; i <= s.length(); i++)
        {
            if (map.count(s[i - 1]) == 0) 
                dp[i] = dp[i-1] + 1;
            else {
                int d = i - 1 - map[s[i - 1]];
                if (d <= dp[i - 1]) 
                    dp[i] = d;
                else 
                    dp[i] = dp[i - 1] + 1;
            }
            maxn = max(maxn, dp[i]);
            map[s[i - 1]] = i - 1;
        }
        return maxn;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}