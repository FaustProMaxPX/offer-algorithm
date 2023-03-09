#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

/*
思路：
因为要查找两个数，因此依旧可以使用双指针。p1指向头部，p2指向尾部
因为p1代表可选的最小的数，因此如果p1 + p2 > target，就代表p2指向的数不可能和之后任何一个数匹配到目标值，可以直接舍弃
如果发现p1 + p2 < target就代表当前的p1不可能和任何可选的后续值匹配了，可以直接舍弃
以上两部循环直到p1和p2相交
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                return {nums[i], nums[j]};
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};

int main(int argc, const char** argv) {
    vector<int> v {2,7,11,15};
    Solution s;
    v = s.twoSum(v, 9);
    for (int num : v) cout << num << " ";
    return 0;
}