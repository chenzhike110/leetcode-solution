#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> res(row, vector<int>(col));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
    }
};

int main() {
    return 0;
}