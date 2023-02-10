#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点

/*
思路1：
利用栈后进先出的特点，反转链表
每从栈中取出一个节点，就将该结点设置为上一个取出节点的next

思路2：
既然能使用栈，就代表可以利用递归实现
递归的最小子问题是整个链表只有一个节点，此时它的逆序就是本身
问题划分：当前节点为头部的链表的逆序=当前节点之后的链表的逆序 -> 当前节点

思路3：
还有一种思路是在遍历过程中反转链表，下面考虑一下每次进行反转需要的变量：
cur：当前节点
pre：反转后当前节点指向的目标
next：确保反转后能够继续向后遍历
每访问一个新的节点，就先记录该结点的下一个节点到next中，然后将cur的next设置为前一个节点
*/

/*
需要考虑的测试用例：
1. 头节点为空
2. 只有一个节点
3. 有多个节点
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stack;
        // 这个判断条件需要考虑head是否不为空！！！
        while (head != nullptr && head->next != nullptr) {
            // 这边注意要将取出的节点从链表中断开
            ListNode* next = head->next;
            head->next = nullptr;
            stack.emplace(head);
            head = next;
        }
        // 此时head指向最后一个节点
        ListNode* pre = head;
        while (!stack.empty()) {
            ListNode* cur = stack.top();
            stack.pop();
            pre->next = cur;
            pre = cur;
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    ListNode* head = new ListNode(2);
    ListNode* node = head;
    node->next = new ListNode(1);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    head = s.reverseList(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}