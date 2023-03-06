#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletionsDP(string s) {
        // b : f(n) = f(n-1)
        // a: f(n) = min(f(n-1)+1, b_before)
        int f = 0;
        int cnt_b = 0;
        for(auto c: s) {
            if(c == 'b')
                cnt_b += 1;
            else
                f = min(f+1, cnt_b);
        }
        return f;
    }
};

int main() {
string s = "bbaaaaabb";
    Solution a;
    int result = a.minimumDeletionsDP(s);
    std::cout << result << std::endl;
    return 0;
}
