#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 输入整数数组 arr ，找出其中最小的 k 个数。

/*
思路：
一道典型的TopK问题，这里可以借鉴快排的思路，将数组划分为小于最小的第k个数的部分，以及其他数字部分
大致的实现思路是，每次划分完毕之后，检查哨兵所在位置是否为k-1，如果是，代表找到了前k个元素，可以返回
如果哨兵所在位置小于k，代表所需要的数据还不够，到右侧数组继续划分出k - j个数据来，如果哨兵所在位置大于k，就到左侧划分出k个数据

还有一种更适合于在海量数据中查找的方法：维护一个大小为k的大根堆，每次遍历到一个新数据，就把他跟堆顶数据比较，如果当前数据更小，就进行替换，否则略过
*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size()) return arr;
        quick_sort(arr, 0, arr.size() - 1, k);
        return vector<int> (arr.begin(), arr.begin() + k);
    }

    void quick_sort(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) --j;
            while (i < j && arr[i] <= arr[l]) ++i;
            swap(arr[i], arr[j]);
        }
        swap(arr[l], arr[i]);
        if (i == k) return;
        // 注意，虽然上面说了这边需要继续划分出k-i个数据来，但这里依旧要传k进去
        // 因为我们传递的是数组引用，不是子数组，所以划分之后获得的索引依旧是整个数组的索引，在比较时是跟k去比的
        else if (i < k) quick_sort(arr, i + 1, r, k);
        else quick_sort(arr, l, i - 1, k);
    }
};

int main(int argc, char const *argv[]) {

    return 0;
}