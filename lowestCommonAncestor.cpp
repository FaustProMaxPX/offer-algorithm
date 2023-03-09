#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 二叉搜索树 -> 公共节点大小必在p和q之间
        // 根据二叉搜索树特性，左子树的值必定小于当前值，右子树的值必定小于当前值
        // 因此如果root大于另两个节点的值，代表公共节点在左子树
        // 若小于，代表在右子树
        // 若一大一小，代表二者在左右子树各有一个，那么当前节点就是公共节点
        if (!root) return nullptr;
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

int main(int argc, const char** argv) {
    return 0;
}