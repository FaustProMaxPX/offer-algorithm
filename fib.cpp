#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1

/*
思路：
从题目描述来看，输出结果会非常大，如果使用最简单的递归，最后会导致调用栈过深，爆内存
因为Fib(n)的计算只需要用到前两次计算的结果，因此我们可以用长度为2的滑动窗口完成本题
如果输入为0或1，直接返回答案。
如果不为0或1，进入循环，循环体内部计算F(k)。每次计算完成后，将窗口中第一个元素剔除，后两个元素前移一格

注意：这里n很大的时候会超过int存储上限，因此每次完成计算后就直接取模
PS (a % c) + (b % c) != (a + b) % c
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int fib(int n) {
        int fib[2] = {0, 1};
        if (n == 0 || n == 1) {
            return fib[n];
        }
        for (int i = 2; i <= n; i++) {
            int t = (fib[0] + fib[1]) % MOD;
            fib[0] = fib[1];
            fib[1] = t;
        }
        return fib[1];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.fib(95) << endl;
    cout << s.fib(5) << endl;
    return 0;
}