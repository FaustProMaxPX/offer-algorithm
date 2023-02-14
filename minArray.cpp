#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。  
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

// 思路：
// 因为数组在旋转之前按照升序排列，因此旋转之后这数组就会被分成两个升序排列的数组，并且前一个升序数组的最小值大于后一个的最大值
// 由于升序特性，当前数组最后一个值就是第二个数组的最大值
// 因此只要二分查找mid的值大于右边界的值，就代表目标不在左侧
// 如果mid的值小于右边界，代表自己处于第二个升序数组，可能是结果，将右边界设置为mid。
// 因为重复值的存在，这里不能像之前那样通过判断前一个值是否比自己大来确定是不是第一个。同时由于mid可能是目标，因此不能将它舍弃
// 如果mid和右边界相等，此时只能判断右边界的当前值可以舍去

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            } else if (numbers[mid] < numbers[r]) {
                r = mid;
            } else {
                r--;
            }
        }
        return numbers[l];
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v = {2,1,2,2,2,2};
    Solution s;
    cout << s.minArray(v);
}