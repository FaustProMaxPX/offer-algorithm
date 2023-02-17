#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

/*
思路：
买卖股票的利润最大，也就代表买入卖出价格的差最大。
传统的方式是将数组中每个元素都和自己之后的元素挨个比较，思路很简单，但时间复杂度为O(n^2)
更有效的方法是，如果我们想在第n天出售股票，那么这一天卖出的最大利润就是当天股价-之前最低买入价
因此我们只需要知道前n-1天中价格最低的时刻就能计算出第n天的最大利润
之后再维护一个全局的最高利润，如果计算出的最高利润大于它就进行替换
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int minp = prices[0];
        // 最低交易额必须为非负数
        int res = max(prices[1] - prices[0], 0);
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i - 1] < minp) minp = prices[i - 1];
            int profit = prices[i] - minp;
            if (profit > res) {
                res = profit;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v = {7,1,5,3,6,4};
    cout << s.maxProfit(v);
    return 0;
}