#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

/*
思路：
使用双指针算法，第一个指针从头开始往后遍历，第二个节点比第一个节点慢k个节点，这样当第一个节点到达最后一个节点时，第二个节点就到达了倒数第k个节点
如果k大于链表总长度，那么直接返回null
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        
        for (size_t i = 0; i < k; i++)
        {
            if (p1 == nullptr) return nullptr;
            p1 = p1->next;
        }

        while (p1) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
};

// template <class T>
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
    vector<int> v {1, 2, 3};
    ListNode* head = create(v);
    Solution s;
    head = s.getKthFromEnd(head, 3);
    print(head);
    return 0;
}