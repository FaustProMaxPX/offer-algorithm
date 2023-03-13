#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

/*
思路：
后序遍历中，根节点在最后一位。因此我们首先从头开始遍历数组，找到首个比根节点大的数
此时，这个数左侧就都是左子树。然后我们继续遍历，确认右子树中没有比根节点更大的数，如果有，就代表不是二叉搜索树
不然的话，就接着检查左右子树是否符合条件
*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int>& postorder, int l, int r) {
        // 校验完毕，返回true
        if (l >= r) return true;
        int root_val = postorder[r];
        int i = l;
        for (; i < r; i++) {
            if (postorder[i] > root_val) break;
        }
        for (int j = i; j < r; j++) {
            if (postorder[j] < root_val) return false;
        }
        // 左子树范围是l，i-1
        bool res = helper(postorder, l, i - 1);
        // 右子树范围是i, r-1
        res &= helper(postorder, i, r - 1);
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<int> v {1,2,5,10,6,9,4,3};
    Solution s;
    cout << s.verifyPostorder(v);
    return 0;
}