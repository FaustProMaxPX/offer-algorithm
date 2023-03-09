#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
/**
 * 思路：
 * 中序遍历下，二叉搜索树是有序的，因此本题需要基于中序遍历进行原地置换
 * 首先对左子树进行链表化，链表化完成后应返回当前链表的最后一个节点，这个节点作为当前节点的前驱节点
 * 接着对右子树进行链表化，当前节点会作为前驱节点，完成链表化后返回链表最后一个节点，然后将左子树序列化完成后的头节点于右子树序列化后的尾节点拼接成循环链表
 * 递归终止条件：
 * 到达叶子节点，本身就是双向链表，再将它改造成循环链表即可
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 前序建树
Node* createTree(vector<int>& vals) {
    if (vals.size() == 0) {
        return nullptr;
    }
    int v = vals[0];
    vals.erase(vals.begin());
    if (v == -1) {
        return nullptr;
    }
    Node* root = new Node(v);
    root->left = createTree(vals);
    root->right = createTree(vals);
    return root;
}

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node* start = helper(root);
        return start->right;
    }

    Node* helper(Node* root) {
        if (!root)  return nullptr;
        // 如果到达子结点，修改为循环链表
        if (!root->left && !root->right) {
            root->left = root;
            root->right = root;
            return root;
        }
        // 如果不是叶子节点
        // 首先链表化左子树
        Node* left_end = helper(root->left);
        // 然后链表化右子树
        Node* right_end = helper(root->right);
        // 获取左子树首个节点,如果左子树不存在,那么当前节点就是左子树首个节点
        Node* left_start = left_end ? left_end->right : root;
        left_end = left_end ? left_end : root;
        // 获取右子树首个节点,如果右子树不存在,那么当前节点就是右子树首个节点
        Node* right_start = right_end ? right_end->right : root;
        right_end = right_end ? right_end : root;
        // 将左子树的尾节点拼接到当前节点之前
        left_end->right = root;
        // 将右子树的头节点拼接到当前节点之后
        right_start->left = root;
        // 将左子树的头节点和右子树的尾节点连接起来
        left_start->left = right_end;
        right_end->right = left_start;
        // root修改指针的操作必须放在后面
        root->left = left_end;
        root->right = right_start;
        return right_end;
    }
};

int main(int argc, const char** argv) {
    vector<int> v {2, 1, -1, -1, -1};
    Solution s;
    s.treeToDoublyList(createTree(v));
    return 0;
}