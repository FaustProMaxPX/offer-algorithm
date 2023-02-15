#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

/*
思路：
这道题就是最简单的层序遍历
初始化一个队列，队列中存储着等待遍历的节点。如果队列中没有节点，代表遍历完成
每从队列中取出一个节点，将它加入返回数组，如果左/右节点不为空，将其放入队列
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> ret;
        q.emplace(root);
        while (!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            ret.emplace_back(t->val);
            if (t->left != nullptr) q.emplace(t->left);
            if (t->right != nullptr) q.emplace(t->right);
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
    vector<int> ret = s.levelOrder(root);
    for (int n : ret) {
        cout << n << endl;
    }
}