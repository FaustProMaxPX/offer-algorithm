#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

/**
 * 思路：
 * 最简单的方法就是挨个判断每个数是否是丑数，直到找到第n个丑数
 * 但是仔细想想，一个丑数应该是由其他丑数乘以2/3/5得出的结果，我们可以借此避免对非丑数的计算
 * 那么接下来要思考的问题就是如何确保计算出来的丑数是有序的，我们可以设置3个临时变量，他们分别表示有希望通过*2/3/5成为下一个丑数的丑数下标
 * 假设临时变量分别为a,b,c，a的左侧代表已经通过*2获取到了新偶数的部分，b和c同理
 * 我们在循环中不断计算三个指针指向元素×2,3,5获取的结果，将获取到的最小的那个数作为新的丑数加入数组，然后将用到的指针向前移动
 * 
*/

int nthUglyNumber(int n) {
    int a = 0, b = 0, c = 0;
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
        // 这里不能用if-else，因为存在dp[a] * 2 == dp[b] * 3的情况，此刻他们都要移动
        if (dp[a] * 2 == dp[i]) ++a;
        if (dp[b] * 3 == dp[i]) ++b;
        if (dp[c] * 5 == dp[i]) ++c;
    }
    return dp[n - 1];
}

int main(int argc, char const *argv[]) {
    nthUglyNumber(10);
    return 0;
}