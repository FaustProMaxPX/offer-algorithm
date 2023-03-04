#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

// 返回删除后的链表的头节点。

/*
思路：
非常简单，遍历链表，找到要删除的节点，断开即可
如果要删除的是头节点，直接返回下一个节点即可
如果是一般节点，需要记录3个节点位置，前一个节点，当前节点，之后的节点
因此在代码里当前节点的体现是node->next
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) return nullptr;
        if (head->val == val) return head->next;
        ListNode* node = head;
        while (node->next) {
            if (node->next->val == val) {
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return head;
    }
};

int main(int argc, const char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    Solution s;
    head = s.deleteNode(head, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}