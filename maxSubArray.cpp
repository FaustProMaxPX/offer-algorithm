#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 要求时间复杂度为O(n)。

/*
思路：
本题中的子问题为子数组的和，我们可以借助所有的子问题的解推出子数组和的最大值，因此符合最优子结构
本题的大致解法为：维护一个表示当前子数组最大和的临时变量。从头开始遍历数组，将当前数组元素加入到当前子数组和中
面对负数时，我们就需要将之前得到的求和结果先存储起来，因为他很有可能就是最大值
如果和小于0，代表已经找到了前面一段子数组的最大和（因为对于之后加入的数来说，这段子数组的和永远都会拖后腿）。
将临时变量与全局最大值比较，取最大的那个
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int t_sum = nums[0];
        int maxn = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if (t_sum <= 0) {
                t_sum = nums[i];
            } else {
                t_sum += nums[i];
            }
            // 每一轮完成计算，都要存储一下结果
            maxn = max(t_sum, maxn);
        }
        return maxn;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v {-1};
    std::cout << s.maxSubArray(v) << std::endl;
    return 0;
}