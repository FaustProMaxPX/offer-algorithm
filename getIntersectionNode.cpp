#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入两个链表，找出它们的第一个公共节点

/*
思路：最简单的做法就是先遍历链表1，将经过的所有节点存储到set中，然后再遍历链表2，查询首个在set中存在的节点
还有另一种做法是，先将两个链表的节点分别存储到两个栈中，然后开始同步出栈，如果某个时刻出栈的节点不同，那么就代表他们前面出栈的节点是第一个公共节点
最后还有一种不需要辅助空间的做法，我们难以在通过遍历找到公共节点的原因在于，两个链表很有可能不会在同一个时间点到达公共节点，因此这里的解决方案就是：
首先将两个链表遍历一遍，获取各自的长度，然后让指向长链表的指针先移动k步，之后二者同时移动，碰到的第一个相同节点就是首个公共节点
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        while (headA) {
            set.emplace(headA);
            headA = headA->next;
        }
        while (headB) {
            if (set.find(headB) != set.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main(int argc, const char** argv) {
    return 0;
}