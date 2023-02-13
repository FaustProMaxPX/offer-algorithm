#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，
// 并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

/*
看到范围0 - n-1，且每个数字唯一，我们就可以直接计算0-n-1的和，然后再算数组的和，最后相减即可
*/

/*
不过这种做法没有很好的利用到升序特性
假设缺失的数据为m，那么所有小于m的元素一定与他们的下标相等，而大于m的都会往左偏移1
因此我们的目标就是找到这个分界点，这里二分法显然是最合适的
如果mid指向的元素与下标相等，那么只要接着扫描右半边，如果不等，判断这是不是首个偏移元素，如果是，它-1就是答案，如果不是，向左二分
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = (n + 1) * n / 2;
        int t = 0;
        for (auto num : nums)
        {
            t += num;
        }
        return sum - t;
    }

    int missingNumber0(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == mid) {
                l = mid + 1;
            } else {
                // 如果是首个偏移点，-1就是答案
                if (mid - 1 < 0 || nums[mid - 1] == mid - 1) {
                    return nums[mid] - 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        // 能达到这一步只有一种可能，缺失的是最后一个元素
        return nums.size();
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    std::cout << s.missingNumber0(nums) << std::endl;
}