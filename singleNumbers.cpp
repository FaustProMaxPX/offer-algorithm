#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
        // 出现两次的数据进行亦或操作会变成0
        // 因此所有数据亦或一遍就是两个只出现一次的数据的亦或结果
        // 接着我们可以根据这个亦或结果,比如0101,代表那两个数最后一位不同,这时就可以将数据分为两组,一组最后一位为0,一组最后一位为1
        // 此时两个目标数分散在两个数组里,再对这两个数组进行^操作,就是结果
        int t1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            t1 ^= nums[i];
        }
        cout << t1 << endl;
        int ti = 1;
        while ((t1 & 1) == 0) {
            ti <<= 1;
            t1 >>= 1;
        }
        cout << ti << endl;
        int r1 = 0;
        int r2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & ti) r1 ^= nums[i];
            else r2 ^= nums[i];
        }
        return {r1, r2};
    }

class Solution {
    public:
    vector<int> arr;

    void convert(int num) {
        for (int i = 0; i < 32; i++) {
            int t = num & 1;
            arr[32 - i - 1] += t;
            num >>= 1;
        }
    }


int singleNumber(vector<int>& nums) {
    for (int i = 0; i < 32; i++) arr.emplace_back(0); 
    // 如果一个数字出现了3次,那么它对应的二进制位也都出现了3次,因此我们把所有32位中各自1出现的次数统计一下,所有无法被3整除的位构成那个唯一出现过的数字
    for (int i = 0; i < nums.size(); i++) {
        convert(nums[i]);
        // print(arr);
    }
    unsigned ret = 0;
    for (int i = 0; i < 32; i++) {
        if (arr[i] % 3) {
            ret |= (1 << (32 - i - 1));
        }
    }
    return ret;
}
};



int main(int argc, const char** argv) {
    vector<int> v {3,4,3,3};
    Solution s;
    cout << s.singleNumber(v);
    return 0;
}