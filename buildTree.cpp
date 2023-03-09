#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

/*
思路：前序遍历中根节点排在最前，找到它在中序遍历中的位置，它的两侧就是它的左右子树
因此本题中，首先从取出前序遍历中的第一个元素，他就是根节点，然后到中序遍历中找到它的位置
将左右两侧的元素，作为下一层递归的中序遍历，并拆分前序遍历，获取左右子树的前序遍历数组，传递给子树构建
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > preorder.size() || pl > pr) return nullptr;
        if (pl == pr) {
            return new TreeNode(preorder[pl]);
        }
        // 获取前序首个元素
        int root_val = preorder[pl];
        int i = il;
        // 查找他在中序中的位置
        for (; i < inorder.size(); i++) {
            if (inorder[i] == root_val) break;
        }
        // 左子树长度
        int length = i - il;
        // 左子树的前序范围为pl + 1, pl + length。中序范围为il, i - 1
        TreeNode* left = helper(preorder, inorder, pl + 1, pl + length, il, i - 1);
        // 右子树的前序范围为, pl + 1 + length, pr。中序范围为i + 1, ir
        TreeNode* right = helper(preorder, inorder, pl + 1 + length, pr, i + 1, ir);
        TreeNode* root = new TreeNode(root_val);
        root->left = left;
        root->right = right;
        return root;
    }
};

int main(int argc, const char** argv) {
    vector<int> pre {3,9,20,15,7};
    vector<int> in {9,3,15,20,7};
    Solution s;
    TreeNode* t = s.buildTree(pre, in);
    cout << t->val << endl;
    return 0;
}