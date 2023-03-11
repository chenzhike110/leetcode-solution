#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubarrayI(vector<int>& nums, int p) {
        unsigned int total = accumulate(nums, 0, nums.size());
        if (total % p == 0) return 0;
        else if (total < p) return -1;
        else {
            // find minimum array
            unsigned int mini = nums.size();
            unsigned int remain = total % p;
            bool found = false;
            for(int i=0; i<nums.size(); i++) {
                unsigned int sum = 0;
                for(unsigned int j=1; j<=mini&&j<=nums.size()-i; j++) {
                    sum += nums[i+j-1];
                    // cout << i << " " << j << " " << sum << " " << mini << " " << nums.size() << endl;
                    // if (sum > remain) break;
                    if (sum % p == remain) {
                        mini = min(j, mini);
                        found = true;
                    }
                }
            }
            if (found) return mini;
            return -1;
        }
    }
    unsigned int accumulate(vector<int> array, int begin, int end) {
        unsigned int result = 0;
        for(int i=begin; i<end; i++) {
            result += array[i];
        }
        return result;
    }
    int minSubarray(vector<int>& nums, int p) {
        int x = 0;
        for (auto num: nums) {
            x = (x + num) % p;
        }
        if (x == 0) return 0;
        unordered_map<int, int> index;
        int res = nums.size();
        int sum = 0;
        int target = 0;
        for (int i=0; i<nums.size(); i++) {
            index[sum] = i;
            sum = (sum + nums[i]) % p;
            target = (sum - x + p) % p;
            int tmp = index.count(target) == 0? nums.size():i-index[target] + 1;
            res = min(tmp, res);
            // cout << sum << " " << target << endl;
        }
        return res == nums.size() ? -1:res;
    }
    int minSubarrayII(vector<int>& nums, int p) {
        int x = 0;
        for (auto num : nums) {
            x = (x + num) % p;
        }
        if (x == 0) {
            return 0;
        }
        unordered_map<int, int> index;
        int y = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            index[y] = i; // f[i] mod p = y，因此哈希表记录 y 对应的下标为 i
            y = (y + nums[i]) % p;
            if (index.count((y - x + p) % p) > 0) {
                res = min(res, i - index[(y - x + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};

int main() {
    // vector<int> nums({3,1,4,2});
    vector<int> nums({8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2});
    // vector<int> nums({26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3});
    int p = 148;
    Solution a;
    int result = a.minSubarray(nums, p);
    cout << result << endl;
    return 0;
}