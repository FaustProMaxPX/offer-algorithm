#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

// 思路：
/*
将字符串拆成两部分，e之前的一部分，e之后的一部分
前一部分可以是小数，后一部分只能是整数
前一部分再拆成两部分，小数点之前和小数点之后，分别判断里面是否全是数字
*/

class Solution {
public:
    bool isNumber(string s) {
        int e1 = s.find('E');
        int e2 = s.find('e');
        if (e1 != s.npos && e2 != s.npos) return false;
        int ei = e1 != s.npos ? e1 : e2;
        int doti = s.find(".", 0, ei);
        
    }
};

int main(int argc, char const *argv[]) {

    return 0;
}