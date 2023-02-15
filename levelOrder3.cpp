#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

// 和上一题没有任何区别，只需要多维护一个标记，指示当前应该正序还是逆序存入 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        q.emplace(root);
        bool rev = false;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> cur_level(n);
            for (size_t i = 0; i < n; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if (rev) {
                    cur_level[n-i-1] = t->val;
                } else {
                    cur_level[i] = (t->val);
                }
                if (t->left != nullptr) q.emplace(t->left);
                if (t->right != nullptr) q.emplace(t->right);
            }
            rev = !rev;
            ret.emplace_back(cur_level);
        }
        return ret;
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
    vector<int> vals = {1, 2, -1, -1, 3, -1, -1};
    TreeNode* root = createTree(vals);
    Solution s;
    vector<vector<int>> ret = s.levelOrder(root);
    for (auto vec : ret) {
        for (auto n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}