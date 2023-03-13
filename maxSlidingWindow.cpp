#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

/*
思路：
使用双端队列deque，在里面记录可能是最大值的元素的下标。
接着遍历数组，如果当前元素小于队列中最大值，将该元素放入队列尾部，因为它有可能在当前元素离开滑动窗口后称为最大值
没碰到一个新的元素，遍历队列，找到首个比自己小的元素，清空在此之后的所有元素，这样保证队头永远是可用的最大元素
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ret;
        if (nums.empty()) return {};
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front() <= i - k) q.pop_front();
            int cur = nums[i];
            while (!q.empty() && nums[q.back()] < cur) q.pop_back();
            q.emplace_back(i);
            if (i >= k - 1)
                ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v {9,10,9,-7,-4,-8,2,-6};
    Solution s;
    
    for (auto n : s.maxSlidingWindow(v, 5)) cout << n << " ";
    return 0;
}