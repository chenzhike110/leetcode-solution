#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> profile = grid;
        for (int i=1; i<profile[0].size(); i++) {
            profile[0][i] = profile[0][i] + profile[0][i-1];
        }
        for (int i=1; i<profile.size(); i++) {
            profile[i][0] = profile[i][0] + profile[i-1][0];
        }
        for (int j=1; j<profile.size(); j++) {
            for (int i=1; i<profile[0].size(); i++) {
                profile[j][i] = max(profile[j-1][i], profile[j][i-1]) + profile[j][i];
            }
        }
        // debug
        for (int j=0; j<profile.size(); j++) {
            for (int i=0; i<profile[0].size(); i++) {
                cout << profile[j][i] << " ";
            }
            cout << endl;
        }
        return profile[profile.size()-1][profile[0].size()-1];
    }
};


int main() {
    Solution a;
    vector<vector<int>> grid;
    grid.push_back(vector<int>({1, 3, 1}));
    grid.push_back(vector<int>({1, 5, 1}));
    grid.push_back(vector<int>({4, 2, 1}));
    a.maxValue(grid);
}