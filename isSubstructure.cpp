#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。

/*
思路：
由于树是一个递归结构，如果我们要判断树A和B是否相等，首先判断当前节点是否相等，然后判断所有子树是否相等
本题中要判断B是否是A的子结构，可以将它转换为树A中有没有和树B相同的子树

算法流程如下：
因为树的递归特性，因此使用递归算法是很容易想到的
如果当前节点相同，代表当前子树可能和B相同，进一步判断子树是否相同
如果节点不同，去左右子树中寻找有没有相同的子结构

需要注意的是，子结构相同与子树相同的区别在于，它只需要一边完全相同即可，不需要两边都满足
还要注意，当我们找到值相同的节点后，就转入判断子树是否相同的逻辑，而非只需要一边满足即可
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return helper(A, B);
    }

    bool helper(TreeNode* A, TreeNode* B) {
        bool res = false;
        if (A && B) {
            if (A->val == B->val) {
                res |= is_same_sub_tree(A, B);
            }
            if (!res) {
                res |= helper(A->left, B);
            }
            if (!res) {
                res |= helper(A->right, B);
            }
        }
        return res;
    }

    bool is_same_sub_tree(TreeNode* A, TreeNode* B) {
        // 如果B为null，代表匹配完成
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;
        bool res = true;
        res &= is_same_sub_tree(A->left, B->left);
        res &= is_same_sub_tree(A->right, B->right);
        return res;
    }   
};



// 前序建树
TreeNode* createTree(vector<int>& vals) {
    if (vals.size() == 0) {
        return nullptr;
    }
    int v = vals[0];
    vals.erase(vals.begin());
    if (v == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(v);
    root->left = createTree(vals);
    root->right = createTree(vals);
    return root;
}

int main(int argc, char const *argv[]) {
    vector<int> a = {1, 0, -4, -1, -1, -3, -1, -1, 1, -1, -1};
    vector<int> b = {1, -4, -1, -1, -1};
    TreeNode* A = createTree(a);
    TreeNode* B = createTree(b);
    Solution s;
    cout << s.isSubStructure(A, B);
}