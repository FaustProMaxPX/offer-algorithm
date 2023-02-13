#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。
*/

/*
很简单的一道题，有两个思路：

思路1：
哈希表：顺序遍历数组，查询哈希表中是否存在该数据，如果存在，代表之前访问过，如果不存在，将数据存入哈希表中。

思路2：
排序：将数组排序，相同的数据就会挨在一起
*/

/*
看了一下书，发现还有其他做法：
题目给出，数组里的数全部都在0 ~ n-1范围内，也就是说，如果没有重复数字，那么数组中每个元素和下标都是对应的。
因此解题的思路就是，顺序遍历数组，如果当前数组元素不等于下标，就将当前元素交换到它应该在的地方。然后再次判断
现在数组元素是否和下标相等，循环直至发现当前数组元素在它应在的位置已有了满足条件的元素，或者当前元素已经满足要求
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int num : nums) {
            if (map.find(num) != map.end()) {
                return num;
            }
            map.emplace(num, true);
        }
        return -1;
    }

    int findRepeatNumber0(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            // 当前元素不满足要求，循环查找数组中应该放在这的数字
            while (nums[i] != i) {
                // 如果在查找过程中，发现自己的位置已经被占了，代表找到重复元素
                // 此时i应该是数组中缺失的元素
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                // 否则交换位置
                swap(nums[i], nums[nums[i]]);
            }
            // 虽然这里是一个两层循环，但由于每次交换都会使至少一个数字归位，因此平均下来内层循环的时间复杂度会降为O(1)
            // 综上所述，这是一个O(n)的算法
        }
        return -1;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> num = {2, 3, 1, 0, 2, 5, 3};
    cout << s.findRepeatNumber(num);
    return 0;
}