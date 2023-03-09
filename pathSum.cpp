#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

/*
思路：
本题依旧是回溯算法
递归终止条件为：
到达叶子节点，如果求和结果等于目标和，存入结果数组，否则直接返回

从根节点开始深度优先遍历，每到达一个节点就将他们加入求和序列中
然后继续往下递归遍历
下层递归完成后，将当前节点从临时数组中删除
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return res;
        vector<int> v;
        helper(root, target, 0, v);
        return res;
    }

    void helper(TreeNode* root, int target, int tsum, vector<int>& vec) {
        if (!root->left && !root->right) {
            if (tsum + root->val == target) {
                vec.push_back(root->val);
                res.push_back(vec);
                // 注意这里一定取消叶子节点的访问
                vec.pop_back();
            }
        }
        // 尚未到达叶子节点，更新tsum和vec
        tsum += root->val;
        vec.push_back(root->val);
        if (root->left) {
            helper(root->left, target, tsum, vec);
        }
        if (root->right) {
            helper(root->right, target, tsum, vec);
        }
        // 删除最后访问的节点
        vec.pop_back();
    }
};

int main(int argc, const char** argv) {
    return 0;
}