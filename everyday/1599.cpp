#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (runningCost > 4* boardingCost)
            return -1;
        vector<int> profiles({0});
        int wait = 0;
        int profile = 0;
        int geton = 0;
        int maxProfile = 0;
        int minOperation = -1;
        for(int i=0; i<customers.size(); i++) {
            wait += customers[i];
            geton = (wait >= 4) ? 4 : wait % 4;
            wait -= geton;
            profile = profiles[i] + geton * boardingCost - runningCost;
            if (profile > maxProfile) {
                maxProfile = profile;
                minOperation = profiles.size();
            }
            profiles.push_back(profiles[i] + geton * boardingCost - runningCost);
        }
        if (wait > 0) {
            profile = profiles.back() + wait / 4 * (4 * boardingCost - runningCost) + std::max((wait % 4) * boardingCost - runningCost, 0);
            if (profile > maxProfile) 
                minOperation = profiles.size() + wait / 4 + ((wait % 4) * boardingCost > runningCost ? 1 : 0) - 1;
        }
        return minOperation;
    }
};

int main(int argc,char *argv[]) {
    int boardingCost = 5;
    int runningCost = 5;
    vector<int> customers({5,0,0,0,0,30});
    Solution a;
    int max = a.minOperationsMaxProfit(customers, boardingCost, runningCost);
    std::cout << max << std::endl;
    return 0;
}