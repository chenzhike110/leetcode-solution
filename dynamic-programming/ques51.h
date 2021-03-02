#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> rows;
    vector<int> dialog2; //右上左下
    vector<int> dialog1; //左上右下
    vector<vector<int>> result;
    int max_line;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> solve;
        max_line = n;
        rows.push_back(0);
        dialog1.push_back(0);
        dialog2.push_back(0);
        for(int i=0;i<n;i++){
            rows[0] = i;
            dialog1[0] = n+i;
            dialog2[0] = i+1;
            back(1);
        }
        vector<vector<string>> final = change_format();
        return final;
    }

    void back(int n){
        if(n==max_line){
            result.push_back(rows);
        }
        for(int i=0;i<max_line;i++){
            bool temp = true;
            for(int j=0;j<rows.size();j++){
                if(i == rows[j] || max_line-(n-i) == dialog1[j] || i+n+1 == dialog2[j]){
                    temp = false;
                    break;
                }
            }
            if(temp){
                rows.push_back(i);
                dialog1.push_back(max_line-(n-i));
                dialog2.push_back(i+n+1);
                back(n+1);
                rows.pop_back();
                dialog1.pop_back();
                dialog2.pop_back();
            }
        }
    }

    vector<vector<string>>change_format(){
        vector<vector<string>> temp_vector;
        for(int i=0;i<result.size();i++){
            vector<string> temp_v;
            for(int j=0;j<result[0].size();j++){
                string temp;
                for(int k=0;k<max_line;k++){
                    if(k!=result[i][j]) temp.push_back('.');
                    else temp.push_back('Q');
                }
                temp_v.push_back(temp);
            }
            temp_vector.push_back(temp_v);
        }
        return temp_vector;
    }
};
