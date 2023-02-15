#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 
// s 只包含小写字母。在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

/*
思路：
使用一个哈希表记录每个字符的出现次数
第一次遍历记录每个字符出现次数，
第二次遍历找到最靠前的只出现一次的字符
由于s只包含小写字母，因此我们可以用一个长度为26的辅助数组来代替哈希表
*/

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(char ch : s)
        {
            map[ch]++;
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            if (map[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.firstUniqChar("") << endl;
    std::cout << s.firstUniqChar("abc") << std::endl;
    std::cout << s.firstUniqChar("aabb") << std::endl;
}