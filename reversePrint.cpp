#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

/*
思路：
不断将链表元素插入到数组头部
比起 vector，deque头部插入的效率更高
*/

/*
还有一种方式是使用栈来完成，利用后进先出的特点实现逆序打印
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        deque<int> q;
        while (head != nullptr) {
            q.push_front(head->val);
            head = head->next;
        }
        return vector<int>(q.begin(), q.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* head = new ListNode(2);
    ListNode* node = head;
    node->next = new ListNode(1);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    auto res = s.reversePrint(head);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}
