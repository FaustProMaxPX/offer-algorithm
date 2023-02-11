#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。
// 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

/*
思路：
依旧使用双指针算法，p1指向原始字符串的起始位置（题目给的数字%len），p2指向新字符串的起点
p1 = (p1 + 1) % length，直到p2的长度达到原始字符串的长度
*/

/*
还有一种原地算法，也是双指针思想
首先考虑纯粹的反转字符串做法：将p1指向字符串起点，p2指向字符串结尾，不断交换二者指向的元素
而左旋字符串的本质是：将前n个字符反转，将剩下的字符反转，最后将整个字符串反转
*/

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        int p1 = n % len; // 因为n可能大于s的长度，因此需要取模
        int p2 = 0;
        string ret(len, ' ');
        for (; p2 < len; p2++) {
            ret[p2] = s[p1];
            p1 = (p1 + 1) % len;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string t = "123";
    cout << s.reverseLeftWords(t, 0);
}