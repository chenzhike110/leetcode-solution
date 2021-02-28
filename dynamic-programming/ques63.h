class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        int result[m][n];
        result[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==0) result[i][0] = result[i-1][0];
            else result[i][0]=0;
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]==0) result[0][j] = result[0][j-1];
            else result[0][j]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0) result[i][j]=result[i-1][j]+result[i][j-1];
                else result[i][j]=0;
            }
        }
        return result[m-1][n-1];
    }
};
