class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int min, result, temp;
        min = prices[0];
        result = 0;
        for(int i=1;i<prices.size();i++){
            temp = prices[i]-min;
            if(temp<0) min = prices[i];
            if(temp>result) result = temp;
        }
        return result;
    }
};
