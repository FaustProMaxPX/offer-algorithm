#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 给定一棵二叉搜索树，请找出其中第 k 大的节点的值。

/**
 * 思路：
 * 二叉搜索树的中序遍历是有序的，一般的遍历方式是先左再右
 * 但这里我们需要第k大元素，因此先右再左遍历，直到到达第k个节点
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int cnt = 0;
    int ans = -1;
    int kthLargest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }

    void helper(TreeNode* root, int k) {
        if (root->right) helper(root->right, k);
        if (++cnt == k) {
            ans = root->val;
        }
        if (root->left) helper(root->left, k);
    }
};

int main(int argc, const char** argv) {
    return 0;
}