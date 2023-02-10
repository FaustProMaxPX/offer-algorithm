#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 请实现 copyRandomList 函数，复制一个复杂链表。
// 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
// 还有一个 random 指针指向链表中的任意节点或者 null

/*
思路：
本题和普通的链表复制的区别在于random指向的目标可能还没有被创建

一种比较容易想到的方法是使用哈希表，哈希表的键值对是<原节点地址，复制节点地址>
每次复制之前都先在哈希表中查询对应节点是否已经复制完成，如果复制好就直接使用对应的复制节点地址，如果没有就进行复制
本质上算是一种回溯法
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> existNodes;

    Node* copyRandomList(Node* head) {
        return copyHelper(head);
    }

    Node* copyHelper(Node* head) {
        if (head == nullptr) return nullptr;

        // 需要进行复制
        if (!existNodes.count(head)) {
            Node* new_head = new Node(head->val);
            // 复制子链表
            new_head->next = copyHelper(head->next);
            // 这里注意需要先将当前节点标记为创建成功再初始化random节点
            // 如果放在后面，犹豫链表中的节点都处于不可用状态，他去初始化一个已经创建的节点，
            // 并且还会陷入死循环，因为找不到可用节点，所以尝试创建，创建又需要那些不可用节点。
            existNodes[head] = new_head;
            new_head->random = copyHelper(head->random);
            return new_head;
        }

        // 如果该节点已经复制完成，直接返回
        return existNodes.at(head);
    }
};

Node* createList(vector<int> vals, vector<int> randoms) {
    Node* head = nullptr;
    unordered_map<int, Node*> node_map;
    int cnt = 0;
    Node* cur_node;
    for (int v : vals) {
        if (head == nullptr) {
            head = new Node(v);
            cur_node = head;
            node_map.emplace(cnt++, head);
        } else {
            Node* node = new Node(v);
            cur_node->next = node;
            cur_node = node;
            node_map.emplace(cnt++, node);
        }
    }

    for (int i = 0; i < randoms.size(); i++) {
        if (randoms[i] == -1) continue;
        Node* node = node_map[i];
        Node* sib = node_map[randoms[i]];
        node->random = sib;
    }
    return head;
}

int main(int argc, char const *argv[]) {
    Node* head = createList({7, 13, 11, 10, 1}, {-1, 0, 4, 2, 0});
    Solution s;
    Node* copy_head = s.copyRandomList(head);
    int cnt = 0;
    while (head != nullptr) {
        cout << "node" << cnt++ << " :" << "\n";
        cout << "   val: " << head->val << "\n";
        string next = head->next != nullptr ? to_string(head->next->val) : "null";
        string random = head->random != nullptr ? to_string(head->random->val) : "null";
        cout << "   next: " << next << "\n";
        cout << "   random: " << random << "\n";
        head = head->next;
    }
    cnt = 0;
    while (copy_head != nullptr) {
        cout << "node" << cnt++ << " :" << "\n";
        cout << "   val: " << copy_head->val << "\n";
        string next = copy_head->next != nullptr ? to_string(copy_head->next->val) : "null";
        string random = copy_head->random != nullptr ? to_string(copy_head->random->val) : "null";
        cout << "   next: " << next << "\n";
        cout << "   random: " << random << "\n";
        copy_head = copy_head->next;
    }
}