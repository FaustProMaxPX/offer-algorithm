#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 统计一个数字在排序数组中出现的次数。

/*
看到排序数组，基本逃不了二分
先用二分查找到目标的索引，然后左右遍历计数。
因为顺序扫描的时间复杂度是O(n)，所以这种算法跟直接遍历数组没什么区别（

不过仔细想想，既然是有序数组了，那只要知道目标值的起始位置和终止位置，就可以确定它的数量了
因此要稍微改造一下二分，当我们发现出现了目标值后，检查这是不是第一个目标值，如果不是，就继续到前面查找
最后一个目标值的查找方式同理
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = searchFirstK(nums, target);
        int end = searchEndK(nums, target);
        if (start == -1 || end == -1) return 0;
        return end - start + 1;
    }

    int searchFirstK(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int tindex = -1;
        // 左闭右闭
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                // 如果说是第一个，直接退出
                if (mid - 1 < 0 || 
                    (mid - 1 >= 0 && nums[mid - 1] != target)) {
                    tindex = mid;
                    break;
                } else {
                    r = mid - 1;
                }
            } else if (nums[mid] < target) {
                // 目标在右半边
                l = mid + 1;
            } else if (nums[mid] > target) {
                // 目标在左边
                r = mid - 1;
            }
        }
        return tindex;
    }

    int searchEndK(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int tindex = -1;
        // 左闭右闭
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                // 如果说是最后一个，直接退出
                if (mid + 1 == nums.size() || 
                    (mid + 1 < nums.size() && nums[mid + 1] != target)) {
                    tindex = mid;
                    break;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < target) {
                // 目标在右半边
                l = mid + 1;
            } else if (nums[mid] > target) {
                // 目标在左边
                r = mid - 1;
            }
        }
        return tindex;
    }
};

int main(int argc, const char** argv) {
    vector<int> nums = {5,7,7,8,8,10};
    Solution s;
    cout << s.search(nums, 1) << endl;
    return 0;
}