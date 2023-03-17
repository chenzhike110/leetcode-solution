#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>sums(nums.size()+1);
        vector<int>res(queries.size());
        sums[0] = 0;
        for(int i=0; i<nums.size(); i++) {
            int index = 0;
            for (int j=1; j<nums.size(); j++) {
                if(nums[j] < nums[index]) {
                    index = j;
                }
            }
            sums[i+1] = sums[i] + nums[index];
            nums[index] = 1000001;
            for(int q=0; q<queries.size(); q++) {
                if(sums[i+1] <= queries[q]){
                    res[q] = i + 1;
                }
            }   
        }
        return res;
    }
};

int main() {
    // vector<int> nums({736411,184882,914641,37925,214915});
    // [736411,184882,914641,37925,214915]
    // [331244,273144,118983,118252,305688,718089,665450]
    // vector<int> queries({331244,273144,118983,118252,305688,718089,665450});
    vector<int> nums({2,3,4,5});
    vector<int> queries({1});
    Solution a;
    vector<int> res = a.answerQueries(nums, queries);
    for(auto i: res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}