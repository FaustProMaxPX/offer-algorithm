#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

/*
思路：
这依旧是一道类似Fib的题目
我们先考虑最简单的情况，1级台阶有1种跳法，2级台阶有两种跳法。
到了3级台阶，要么是从1级台阶网上跳2级，要么是从2级台阶网上跳1级，因此3级台阶的跳法个数等于1级台阶跳法和2级台阶跳法的总和
推广到一般情况就是F(n) = F(n-1) + F(n-2)

这里答案依旧要求取模，可见输出会很大，因此每次完成计算后直接取模
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(int n) {
        int f[2] = {1, 1};
        if (n == 0 || n == 1) return 1;
        for (size_t i = 2; i <= n; i++)
        {
            int t = (f[0] + f[1]) % MOD;
            f[0] = f[1];
            f[1] = t;
        }
        return f[1];
    }
};