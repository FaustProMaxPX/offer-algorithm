#include <iostream>
#include <stack>
#include <vector>

/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
*/

/*
思路：
新建两个栈，栈A用于接收输入数据，栈B用于输出数据。当栈B发现无数据可输出时，
将栈A的数据加入栈B。若仍然没有数据，返回-1
*/

using namespace std;

class CQueue {
public:

    stack<int> in_stack;
    stack<int> out_stack;

    CQueue() {
        
    }
    
    void appendTail(int value) {
        in_stack.emplace(value);
    }
    
    int deleteHead() {
        // 输出栈不为空，直接输出
        if (!out_stack.empty()) {
            int ret = out_stack.top();
            out_stack.pop();
            return ret;
        }
        // 输出栈为空，将输入栈所有数据加入进来
        while (!in_stack.empty()) {
            int num = in_stack.top();
            out_stack.emplace(num);
            in_stack.pop();
        }
        // 如果输出栈还是为空，代表队列里没数据，返回-1
        // 否则返回顶部数据
        if (out_stack.empty()) return -1;
        int ret = out_stack.top();
        out_stack.pop();
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    vector<string> cmds = {"CQueue","appendTail","deleteHead","deleteHead","deleteHead"};
    vector<vector<int>> nums = {{}, {3}, {}, {}, {}};
    CQueue* q;
    vector<string> res;
    for (size_t i = 0; i < cmds.size(); i++)
    {
        string cmd = cmds[i];
        if (cmd == "CQueue") {
            q = new CQueue();
            res.push_back("NULL");
        } else if (cmd == "appendTail") {
            q->appendTail(nums[i][0]);
            res.push_back("NULL");
        } else if (cmd == "deleteHead") {
            int ret = q->deleteHead();
            res.push_back(to_string(ret));
        }
    }
    for (string re : res)
    {
        cout << re << " ";
    }
    
    return 0;
}
