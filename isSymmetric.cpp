#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

/*
思路：
前面已经实现过了创建二叉树镜像，这里只需要稍加更改就行
如果是空树/只有一个节点的树，显然是对称的，如果不是，比较左右子树是否镜像

如何比较子树是否相同：
如果两子树均为null，相同，如果有一个的根节点为null，不同。如果根节点数据不同，不同
然后使用递归进一步比较左右子树是否相等
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        return is_same(root->left, root->right);
    }   

    bool is_same(TreeNode* A, TreeNode* B) {
        if (!A && !B) return true;
        if (!A || !B || A->val != B->val) return false;
        return is_same(A->left, B->right) && is_same(A->right, B->left);
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}