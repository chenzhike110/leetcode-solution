#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> cnt;
        vector<string> return_names;
        for(auto &name:names) {
            if (cnt.count(name)) {
                string tmp_name = name+"("+to_string(cnt[name])+")";
                while(cnt.count(tmp_name)) {
                    cnt[name] ++;
                    tmp_name = name+"("+to_string(cnt[name])+")";
                    // std::cout << tmp_name << std::endl;
                }
                name = tmp_name;
            }
            cnt[name] = 1;
        }
        return names;
    }
};

int main() {
    Solution a;
    vector<string> names({"kaido","kaido(1)","kaido","kaido(1)","kaido(2)"});
    auto solution = a.getFolderNames(names);
    for (vector<string>::iterator iter=solution.begin(); iter!=solution.end(); iter++)
        std::cout<< *iter;
}