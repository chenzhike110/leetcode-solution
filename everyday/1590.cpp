#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unsigned int total = accumulate(nums, 0, nums.size());
        if (total % p == 0) return 0;
        else if (total < p) return -1;
        else {
            // find minimum array
            unsigned int mini = nums.size();
            unsigned int remain = total % p;
            bool found = false;
            for(int i=0; i<nums.size(); i++) {
                for(unsigned int j=1; j<=mini&&j<=nums.size()-i; j++) {
                    unsigned int sum = accumulate(nums, i, i+j);
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
};

int main() {
    // vector<int> nums({3,1,4,2});
    vector<int> nums({26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3});
    int p = 26;
    Solution a;
    int result = a.minSubarray(nums, p);
    cout << result << endl;
    return 0;
}