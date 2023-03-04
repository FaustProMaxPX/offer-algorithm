#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

/*
前置考虑：是否允许破坏原有数据结构
思路：
很普通的归并排序，使用两个指针，p1指向链表1，p2指向链表2。
如果p1->val > p2->val p2接入并后移
如果p1->val <= p2->val p1接入并后移

p1和p2中有一个为空就跳出循环
然后将不为空的那条链表剩余部分全部接入
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 建立一个哑节点，方便后续操作
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                node->next = new ListNode(l1->val);
                node = node->next;
                l1 = l1->next;
            } else {
                node->next = new ListNode(l2->val);
                node = node->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            node->next = l1;
        }
        if (l2) {
            node->next = l2;
        }
        return head->next;
    }
};

ListNode* create(vector<int>& vec) {
    if (vec.empty()) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    ListNode* node = head;
    for (int i = 1; i < vec.size(); i++) {
        node->next = new ListNode(vec[i]);
        node = node->next;
    }
    return head;
}

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main(int argc, const char** argv) {
    vector<int> v1 {1, 2, 4};
    vector<int> v2 {1};
    ListNode* l1 = create(v1);
    ListNode* l2 = create(v2);
    Solution s;
    print(s.mergeTwoLists(l1, nullptr));
    return 0;
}