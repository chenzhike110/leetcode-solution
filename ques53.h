#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int> ends;
        int temp = nums[0];
        for(int i=1;i<nums.size();i++){
            temp = temp + nums[i];
            if(temp < nums[i]) temp = nums[i];
            ends.push_back(temp);
        }
        temp = nums[0];
        for(int i=0;i<ends.size();i++){
            if(temp < ends[i]) temp = ends[i];
        }
        return temp;
    }
};
