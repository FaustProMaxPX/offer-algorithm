#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

/*
思路：
这题依旧是层序遍历，区别在于我们需要确定哪些元素属于哪一行
当某一层的节点被完全遍历完之后，此时队列中的就是下一行的所有节点
因此我们的解决方案就是，每完成一行的遍历，就记录一下下一行的节点个数，从队列中pop出指定个数的节点放到返回数组中
因为第一层只有一个根节点，因此初始条件为1
*/

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
        while (!q.empty())
        {
            int n = q.size();
            vector<int> cur_level(n);
            for (size_t i = 0; i < n; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                cur_level[i] = (t->val);
                if (t->left != nullptr) q.emplace(t->left);
                if (t->right != nullptr) q.emplace(t->right);
            }
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