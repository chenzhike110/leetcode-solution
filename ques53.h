class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int result = nums[0];
        int temp = nums[0];
        for(int i=1;i<nums.size();i++){
            temp = temp + nums[i];
            if(temp < nums[i]) temp = nums[i];
            if(temp > result) result = temp;
        }
        return result;
    }
};
