#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> maps(n, vector<int>(n));
        vector<int> numRoads(n);
        for(auto road: roads) {
            numRoads[road[0]] += 1;
            numRoads[road[1]] += 1;
            maps[road[0]][road[1]] = 1;
            maps[road[1]][road[0]] = 1;
        }
        int max_road = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int total = numRoads[i]+numRoads[j]-maps[i][j];
                max_road = max(total, max_road); 
            }
        }
        return max_road;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> roads({{0,1},{0,3},{1,2},{1,3}});
    Solution a;
    int result = a.maximalNetworkRank(n, roads);
    cout << result << endl;
}