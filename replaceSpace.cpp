#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

/*
思路：
很无脑的一道题，循环即可。
觉得他很无脑的人本身也很无脑（

由于本题中是将一个字符的空格替换为3个字符的%20，不像一般的字符串替换一样可以直接原地实现
需要进行数组扩容。最一般的做法是不断循环找到空格，然后替换成%20，不过每次替换都需要移动数组，时间复杂度是O(n^2)
这种做法慢的原因在于，每碰到一个空格就需要进行一次空间调整，因此优化的第一个方面就是在最开始分配好足够的内存
完成数组扩容之后，可以使用双指针进一步降低时间复杂度，这里将p1指向原字符串末尾，p2指向新空间的末尾
从后向前遍历的原因在于：如果从前向后遍历，每次都要移动数组，效率太低，而从后向前可以避免移动数组
*/

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int ori = 0; // 原始长度
        int rel = 0; // 扩容后长度
        for (char ch : s) {
            ori++;
            if (ch == ' ') {
                rel += 3;
            } else {
                rel++;
            }
        }

        int p1 = ori;
        int p2 = rel;
        string ret(rel, ' ');
        for (; p1 >= 0; p1--) {
            if (s[p1] == ' ') {
                ret[p2--] = '0';
                ret[p2--] = '2';
                ret[p2--] = '%';
            } else {
                ret[p2--] = s[p1];
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    string s;
    Solution so;
    cout << so.replaceSpace(s) << endl;
    cout << s << endl;
}