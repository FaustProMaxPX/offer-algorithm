#include <iostream>
#include <algorithm>
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。
*/

/*
思路：
在栈中维护一个链表，每个链表节点包含当前值，下一个节点的地址以及插入时链表中的最小值
插入节点时，比较新值与原来的最小值，将更小的那个作为新结点的最小值
正确定：每个节点都存储了自己插入时链表里的最小值，因为栈的先进先出特性，
这个最小值一定不会是在自己插入之后被加入的，因此如果出现了比当前记录最小值更小的值
那一定是后来插入的，依据后进先出，它也会在当前节点之前被弹出。
*/

struct Node
{
    int val;
    int min;
    Node* next;
    Node(int v, int m, Node* n) {
        val = v;
        min = m;
        next = n;
    }
};


class MinStack {
public:

    Node* head = nullptr;

    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (head == nullptr) {
            head = new Node(x, x, nullptr);
        } else {
            head = new Node(x, std::min(x, head->min), head);
        }
    }
    
    void pop() {
        if (head == nullptr) return;
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int min() {
        return head->min;
    }
        
};

using namespace std;

int main(int argc, char const *argv[])
{
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl;  
    minStack.pop();
    cout << minStack.top() << endl;      
    cout << minStack.min() << endl;   

    return 0;
}
