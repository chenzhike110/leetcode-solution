class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j<1){
                    if(i<1){
                        result[0][0] = grid[0][0];
                    }
                    else{
                        result[i][j] = result[i-1][j]+grid[i][j];
                    }
                    continue;
                }
                if(i<1){
                    result[i][j] = result[i][j-1]+grid[i][j];
                    continue;
                }
                result[i][j] = result[i][j-1]<result[i-1][j]? result[i][j-1]+grid[i][j]:result[i-1][j]+grid[i][j];
            }
        }
        return result[m-1][n-1];
    }
};
