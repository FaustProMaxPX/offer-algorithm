#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

/**
 * 思路：
 * 这道题是二叉搜索树公共祖先的翻版，只不过这回没有有序特性可以利用
 * 既然是关于树的题，那首先还是想到使用递归：
 * 递归的终止条件：
 * 1. 越过目标节点，返回null
 * 2. 刚好到达目标节点，返回目标节点
 * 因此，我们对子树递归调用获得的结果就是目标节点或者null
 * 如果子树返回了目标节点，那就代表这一侧存在目标节点，下面分情况讨论：
 * 1. 如果左子树返回null，代表两个节点都在右子树，直接返回右子树获取的结果
 * 2. 如果右子树返回null，代表两个节点都在左子树，直接返回左子树的结果
 * 3. 如果都不为null，代表节点在两侧，此时当前节点就是公共节点
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }
};

int main(int argc, const char** argv) {
    return 0;
}