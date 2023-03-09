#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

/*
思路：
使用双指针，一个指向数组头部一个指向尾部。
p1先不断移动，在遇到偶数时停下。p2接着向前移动，在遇到奇数时停下
二者相交时循环停止
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            // 这里要保证 i < j 否则在全是奇数的情况下，i最终会越界
            while (i < j && nums[i] % 2 != 0) i++;
            while (i < j && nums[j] % 2 != 1) j--;
            // 循环过后i和j可能已经交错，这里额外判断一下
            if (i < j) swap(nums[i], nums[j]);
        }
        return nums;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> v {1, 3, 5};
    v = s.exchange(v);
    for (int num : v) cout << num << " ";
    return 0;
}