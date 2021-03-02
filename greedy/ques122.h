#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool holding = false;
        int in = 0;
        int total_reward = 0;
        int i;
        for(i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i] && !holding){
                holding = true;
                in = prices[i];
                continue;
            }
            if(holding && prices[i+1]<prices[i]){
                holding = false;
                total_reward += prices[i]-in;
            }
        }
        if(holding){
            total_reward += prices[i]-in;
        }
        return total_reward;
    }
};
