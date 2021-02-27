class NumArray {
public:
    vector<int> result;
    NumArray(vector<int>& nums) {
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            temp += nums[i];
            result.push_back(temp);
        }
    }

    int sumRange(int i, int j) {
        if(i > 0) return result[j]-result[i-1];
        else return result[j];
    }
};
