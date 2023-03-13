#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 输入一个字符串，打印出该字符串中字符的所有排列。

/*
思路：
将全排列问题分解成多个子问题
如果只有一个字符，代表它本身就是全排列
如果不止，那么我们可以先确定排列中首个字母，然后接着递归求解剩下部分的全排列

转换为代码就是：
如果字符串为空，代表完成匹配，将当前拼接起来的字符串添加到返回数组
如果只剩一个字符，将它添加到当前字符串添加到返回数组并返回
如果不止一个，让字符串中的每个字母挨个当首个字符，然后继续求解剩下部分的全排列
*/

vector<string> ret;

void helper(string s, string cur);

vector<string> permutation(string s) {
    helper(s, "");
    return ret;
}

void helper(string s, string cur) {
    if (s.length() == 0) return;
    if (s.length() == 1) {
        cur.append(s);
        ret.emplace_back(cur);
        return;
    }
    unordered_set<char> set;
    for (int i = 0; i < s.length(); i++) {
        // 遇到相同字母时，进行剪枝，同时也相当于去重
        if (set.find(s[i]) != set.end()) continue;
        set.emplace(s[i]);
        swap(s[0], s[i]);
        helper(s.substr(1), cur + s[0]);
    }
}

int main(int argc, char const *argv[]) {
    permutation("sas");
    for (auto s : ret) cout << s << " ";
    return 0;
}