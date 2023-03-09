#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

/*
思路：
首先将数组排序，然后开始遍历，碰到0，就像计数器+1。如果碰到中断点，就用之前存的0来填补，填补不了就代表不连续。如果最终能顺利遍历完，就代表连续
否则代表不连续
*/

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        int c = pre == 0 ? 1 : 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) c++;
            // 如果当前数和之前的数一样且不为0，那么肯定不连续
            if (nums[i] == pre && pre != 0) return false;
            // 如果前置为0，那么当前数可以为任何数
            // 否则就要判断二者之间的距离
            if (pre != 0) {
                int t = nums[i] - pre;
                if (t != 1) c = c -= t - 1;
                if (c < 0) return false;
            }
            pre = nums[i];
        }
        return true;
    }
};

int main(int argc, const char** argv) {
    vector<int> v {1, 3, 5, 7, 0};
    Solution s;
    cout << s.isStraight(v);
    return 0;
}