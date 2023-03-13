#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

const int MOD = 1e9+7;

/*
思路：
这道题可以使用类似动态规划的方法完成，将dp[i]表示为长度为i的绳子**裁剪**后获得的乘积最大值
因此dp[i]的求解可以分为以下几种情况，将绳子分成长度为j与长度为i-j的两部分
dp[i]是j/i-j进行裁剪与不进行裁剪的4中排列组合中取得的最大值
dp[i] = max(dp[j]*dp[i-j], dp[j]*(i-j),dp[i-j]*j,j*(i-j))
*/

using namespace std;

int main(int argc, char const *argv[]) {

    return 0;
}