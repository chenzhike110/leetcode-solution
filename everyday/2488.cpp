#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int sign(int i, int j) {
        if (i == j) return 0;
        else return i > j ? 1: -1;
    }
    int countSubarrays(vector<int>& nums, int k) {
        int Kindex = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == k) {
                Kindex = i;
                break;
            }
        }
        int sum = 0;
        int res = 0;
        unordered_map<int, int> maps;
        maps[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            sum += sign(nums[i], k);
            cout << sum << endl;
            if(i < Kindex) {
                maps[sum] ++;
            }
            else {
                if(maps.count(sum) > 0){
                    res += maps[sum];
                }
                if(maps.count(sum-1) > 0) {
                    res += maps[sum-1];
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums({2,3,1});
    int k = 2;
    Solution a;
    int res = a.countSubarrays(nums, k);
    cout << res << endl;
    return 0;
}