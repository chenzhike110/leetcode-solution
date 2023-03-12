#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> index;
        vector<string> result;
        int Alpha_Num = 0, Number_Num = 0;
        for (auto s:array) {
            if (isdigit(s[0])) Number_Num += 1;
            else Alpha_Num += 1;
        }
        
        if (Alpha_Num == 0 || Number_Num == 0) {
            return result;
        }

        int target = Alpha_Num - Number_Num;
        int begin = 0, end = 0;
        Alpha_Num = 0, Number_Num = 0;
        index[0] = 0;
        target = 0;

        for (int i=0; i<array.size(); i++) {
            if (!index.count(target)) {
                index[target] = i;
            }

            if (isdigit(array[i][0])) Number_Num += 1;
            else Alpha_Num += 1;
            target = Alpha_Num - Number_Num;
            
            // cout << Alpha_Num << " " << Number_Num << " " << target;
            if (index.count(target)) {
                // cout << " index :" << target << " " << index[target];
                if ((i - index[target]) > (end - begin)) {
                    begin = index[target];
                    end = i+1;
                }
            }
            // cout << " " << begin << " " << end << endl;
        }
        result = vector<string>(array.begin()+begin, array.begin()+end);
        return result;
    }
};

int main() {
    // vector<string> array({"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"});
    // vector<string> array({"A","1"});
    vector<string> array({"A","A"});
    Solution a;
    vector<string> result = a.findLongestSubarray(array);
    for (auto s:result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}