#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

/*
思路：
镜像二叉树的本质就是交换左右子树
我们依旧使用递归实现，将左子树的复制结果交给镜像树的右节点，右子树反之

还有一种迭代做法，就是利用栈将子树一层一层翻转
首先将根节点入栈，然后进入循环，循环终止条件是栈为空
取出栈顶节点，翻转左右子树，然后将左右子树入栈
事实上这边无所谓用什么数据结构存储节点，只要能让整棵树从上到下或者从下到上依此反转就行了
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* mirror = new TreeNode(root->val);
        mirror->left = mirrorTree(root->right);
        mirror->right = mirrorTree(root->left);
        return mirror;
    }   
};

int main(int argc, char const *argv[]) {
// so easy
// 不想写测试
    return 0;
}