class NumMatrix {
public:
    vector<vector<int>> sum_over;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int> temp;
            sum_over.push_back(temp);
        }
        if(matrix.size() == 0) return;
        sum_over[0].push_back(matrix[0][0]);
        for(int i=1;i<matrix.size();i++) sum_over[i].push_back(sum_over[i-1][0]+matrix[i][0]);
        for(int j=1;j<matrix[0].size();j++) sum_over[0].push_back(sum_over[0][j-1]+matrix[0][j]);
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                sum_over[i].push_back(sum_over[i-1][j] + sum_over[i][j-1] - sum_over[i-1][j-1] + matrix[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1>0 && col1>0)
        return sum_over[row2][col2] + sum_over[row1-1][col1-1] - sum_over[row1-1][col2] - sum_over[row2][col1-1];
        if (row1>0)
        return sum_over[row2][col2] - sum_over[row1-1][col2];
        if (col1>0)
        return  sum_over[row2][col2] - sum_over[row2][col1-1];
        else return sum_over[row2][col2];
    }
};
