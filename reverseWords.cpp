#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

// 无空格字符构成一个单词。
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

/*
思路：
这道题可以当作反转字符串的变种，我们可以首先将整个字符串反转，然后挨个去反转单词
在反转单词期间消去多余的空格
*/

class Solution {
public:
    string reverseWords(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        int i = 0, j = s.length() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        i = 0;
        while (i < s.length()) {
            // 如果i为空格，代表有多余的空格，跳过
            while (s[i] == ' ') i++;
            int j = i;
            while (s[j] != ' ' && j < s.length()) j++;
            int t1 = i, t2 = j - 1;
            while (t1 < t2) {
                swap(s[t1], s[t2]);
                t1++;
                t2--;
            }
            i = j + 1;
        }

        int index = 0;
        while (index < s.length() && (index = s.find(' ', index)) != s.npos) {
            int end = s.find_first_not_of(' ', index);
            if (end - index != 1) {
                s.erase(index + 1, end - index - 1);
            }
            index++;
        }
        return s;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.reverseWords(" ");
    return 0;
}