#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

/*
思路：
如果一个数要出栈，那代表在它之前的数据已经全部入栈，因此我们可以遍历出栈数组
每碰到一个元素就将它之前还没有入栈的元素全部入栈，然后将自己也入栈 实现：用一个变量记录上一次入栈的最后一个元素位置
接着将栈顶元素弹出，比较是否与当前元素相同
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        auto pre = pushed.begin();
        for (int num : popped) {
            auto end = find(pushed.begin(), pushed.end(), num);
            for (; pre <= end; pre++) s.emplace(*pre);
            int t = s.top();
            if (t != num) return false;
            s.pop();
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> t1 {1,2,3,4,5};
    vector<int> t2 {4,3,5,1,2};
    cout << s.validateStackSequences(t1, t2);
    return 0;
}