#include <functional>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

/*
思路：
还是借鉴快排的思想，将数组划分为小于中位数的和大于中位数的两部分。
奇数情况很好解决，就相当于找到n/2位的数字。
偶数情况稍显复杂，首先跟奇数情况一样，找到排名n/2-1的数字，此时左半部分都小于中位数之一，
那么另一个中位数肯定在右半边，只需要对右半部分数组再调用一次快排就行了
*/

/*
思路：
上面的思路虽然能够实现，但在数据量大的情况下效率很低。
因此下面进行进一步的优化，我们通过观察发现，整个数组最终会被分成两部分，左半部分的数据绝对小于右半部分的数据
并且左半部分的最后一个数据需要是他们的最大值，右半部分需要是他们的最小值。（因为我们要获取中位数，因此这么设计）
所以我们可以想到利用一个大顶堆一个小顶堆来完成上面的操作。
在插入时，我们首先要确保两个堆的大小差距不超过1，因此可以在总数为偶数时将数据插入右侧，奇数时插入左侧
这么做就又引出了一个问题，如果总数为偶数时要插入右侧的数据比左侧部分数据小，那就需要先将左侧的最大值放到右侧，再将当前数据放入左侧
要插入左侧的数据比右侧部分数据大也是一样的，首先将右侧最小值移到左侧，再插入当前数据
*/


class MedianFinder {
private:
    
    // vector<int> arr;
    // void quick_sort(int l, int r, int k) {
    //     if (l >= r) return;
    //     int i = l, j = r;
    //     while (i < j) {
    //         while (i < j && arr[j] >= arr[l]) --j;
    //         while (i < j && arr[i] <= arr[l]) ++i;
    //         swap(arr[i], arr[j]);
    //     }
    //     swap(arr[l], arr[i]);
    //     if (i == k) return;
    //     else if (i < k) quick_sort(i + 1, r, k);
    //     else quick_sort(l, i - 1, k);
    // }
    priority_queue<int, vector<int>, less<int>> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
public:

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // 偶数情况
        if (((left_heap.size() + right_heap.size()) & 1) == 0) {
            if (!left_heap.empty() && num < left_heap.top()) {
                // 先将当前数字插入左侧，然后将左侧最大值弹出，作为插入要插入右侧的值
                left_heap.emplace(num);
                num = left_heap.top();
                left_heap.pop();
            }
            right_heap.emplace(num);
        } else {
            if (!right_heap.empty() && num > right_heap.top()) {
                right_heap.emplace(num);
                num = right_heap.top();
                right_heap.pop();
            } 
            left_heap.emplace(num);
        }
    }
    
    double findMedian() {
        int size = left_heap.size() + right_heap.size();
        if ((size & 1) == 0) return (double) (left_heap.top() + right_heap.top()) / 2;
        else {
            if (left_heap.size() == size / 2 + 1) return left_heap.top();
            else return right_heap.top();
        }
    }
    
    // void addNum(int num) {
    //     arr.push_back(num);
    // }
    
    // double findMedian() {
    //     int tar = arr.size() / 2;
    //     // 如果是奇数
    //     if (arr.size() % 2) {
    //         quick_sort(0, arr.size() - 1, tar);
    //         return arr[tar];
    //     } else {
    //         quick_sort(0, arr.size() - 1, tar - 1);
    //         quick_sort(tar, arr.size() - 1, tar);
    //         // 这里记得类型转换
    //         return (double) (arr[tar - 1] + arr[tar]) / 2;
    //     }
    // }

    
};

int main(int argc, const char** argv) {
    MedianFinder f;
    f.addNum(1);
    f.addNum(2);
    f.addNum(-1);
    cout << f.findMedian() << endl;
    // f.addNum(4);
    // cout << f.findMedian() << endl;
    return 0;
}