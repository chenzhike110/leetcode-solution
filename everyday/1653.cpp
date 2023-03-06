#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions1(string s) {
        int last_A = 0;
        int first_B = 100000;
        int result = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a')
                last_A = i;
            else if(i < first_B)
                first_B = i;
        }
        if (last_A > first_B){
            // std::cout << s.substr(first_B, last_A-first_B) <<std::endl;
            // std::cout << s.substr(first_B+1, last_A-first_B) <<std::endl;
            int delete_A = minimumDeletions1(s.substr(first_B, last_A-first_B));
            int delete_B = minimumDeletions1(s.substr(first_B+1, last_A-first_B));
            result += min(delete_A, delete_B) + 1;
        }
        return result;
    }
    int minimumDeletions(string s) {
        int last_A = 0;
        int first_B = 100000;
        int result = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a')
                last_A = i;
            else if(s[i] == 'b' && i < first_B)
                first_B = i;
        }
        if (last_A > first_B) {
            result = 100000;
            int delete_B = 0;
            int delete_A = count(s.begin()+first_B, s.end(), 'a');
            for (int i=first_B; i<=last_A; i++) {
                if (s[i] == 'a')
                    delete_A -= 1;
                result = min(result, delete_A + delete_B);
                // cout << delete_B << delete_A << "\n";
                if (s[i] == 'b')
                    delete_B += 1; 
            }
        }
        return result;
    }
    int minimumDeletionsDP(string s) {
        
        return result;
    }
};

int main() {
    // string s = "bbabbbbbbbababbabbaababaabaaaabaaabbbabbabbabbbbbbbaabbaaaaabababbbabbbabbababbaabbbaabbbbabbaabaaabbbaaaaabbababbabbaaabaabbabbaabbbbabbabbabbbaaaaabbbbbbababababbbbaaaaabbabbabaabbabbbababaabbbabbababbababbbbaabbaabababaaabaaabaaabababbbaabbaaabaaaabababbabbbaababaababaabbbbbaabaaaaaabaaabaabaaaaabbaaabaabaaabaaaaababbbbaababbabbbabbaabaaaababbabbbbaabababaaaaaababbbbabaabbbbbaaaabbbaabbbaaababbbbaabababbbaabaaaabbababaabbbbbbbaaabaaabbbaaaaaaababaaabbaaaabbbbabbaaaaabbbbabaabbabbabbabbbbbabbbbbaaaabbbbabbbabbabbbababbbbbbaababbbabbbbbabaabbabaabbbbbaababbbaabaabbbabbababababbaaaabaabaababbbaabaabaaabababbabbbaabaababbaaaabbbbbbbbbaabbbbaaaaabaabbabbbaaaabbaaababbabaaabbbaaabaabbbababbbbaaaaaabbbbbabbaaaabaabababbbbabbbbbbbaaaaabbaaabaabbaababbbabbababbabbbaabaabbbababbbaabbaaababaabbaabaaabbaaabbabbabbabbabbbbbbaabbaabbbbbabbabbabaabbaabbaababaabbaaaabbbaababaabbbaaabababbababaababbbbaaaaabaaabbababbbaaabaabababaababbbbaaabbbabaababbbababbabbbabaaabbbbabbabaabbabaaabaabbbbbabbbaabaabaaabbaaaaaababaaabbabaababbbabaaabaababaaabbbaaabababaababaabbbaababaaabbbaababbaaaabaabbbabaababbbabbaababababaaaaaaabbaabbabbbbbbbabaabaabaaaabbabababaaaabbbbbabaaaaaabaabbaababbbaaababaaabbbabbbabaabbaababbaabaaabbaaabaabaabaababbbabaaabbabababaabbbaabaaaaaaababaaababaabbabaaaabaaaaabbababaaaabbbbaaabaaaaababbaaaabaaabbabaaaaaabbbaabaabbabbababbaabbbababbbabbabbbaaabaaaaabaababbbbbbabaabbbaabbabababbbbabbbaabaaaabbbbbbaaabaababbbabbaababaaabbaabaabbbbababbbaaabaaabbbabbbbbabbbaaabbabbaababaaabbbababbbaaaaaabaaaaabbbaaabababbbaabbaaaaaababbbbbaabaaabaaaaaaaaaaaabbbabbbbababaababbaabbbaabaaabababbbaaabbabbabbaaaaababababbbbabbaabaaababbbbaaaabbbbaababbaabaaaababbabbabaaabbabbbababbbbbababaababbabbbaababbaababbbbbababbbbbbbabaaabbaabbabaaababaaabbbababaaaabbaabaababbbbaaabbbbaabbabbaababbbaabbbbaaabaaaaabbabbabbaababbaababbaaabbbaabbaaabbabbaaababbbabaaaabaaabbbbabbbbaaaaabbabaaaaabbaaabababbabbbaaaababaabaabaababbaabbbabbabaabababbaaaabbbbbbbaaabbabbabababababaababbbbaabaaaabbbabbabbbbabbbbbabbababbaaaaaaaabababaaabaaabbaaaababaaabaaaabbabbaaababaababaaabbbaaaaaaabababbaabaabaabaaaabbaaaaaaabaaaabbabbbbaabaaababbaabbaabaabaaabbbaaaaaabababbbbaabbaabbbbbbababbaaaaaaabbabaaaabbaabaaaabaababaaabbbbbbbbabbbbabbabbbbaaabbbbbaaababbababbaabbaaaaabbbaabaabaaaaabbabaaabbbabaabaabbbbbaababbabbaabbbbabbabaaaabaaaaaabbbababbbbbbaababbbabbabbaaabaaabbbabaabbbabbabbbbaabbabbbbbbaabaaaabbaaaaaaaaaabaaabaababababbbbabbabbbbbbabaabaaaabbbbbbbaaabaabaaababbbaabbaabbbbbaaabbbaababaaabbbbbbbaabbbaabbbabbbaabaaabbbbaaaaaababbbabaaabbbbbbaabbaaababaabaaaababbbaaaaabaabbabbbabaaabaabbbbbaabbbbbabbabaababbabbaabaaabbbbbaabbbbaabbbbabbabbaabbbbbbaaabbbbbbbabbaaababbbabbbababaaaaababaaabbaaaababbbababbbbababaabbababbbaaaabbbaaaabaababbbabababaaaaaaabbaabaaaaaaabbbbbbbaaabaaabaabbaabaaabaabababaaaaabbbabaabbabbbbabbbabaaaabbabbaaabbbabbbbaababbaaabaaaaabbababaabaabaaaaabbbaabaaaabbbababaabaabaaababbbababbbbababababbbbaaabbbabbbbaababbbbbabbbbbabaabbaaabaabaaaabbbbbbaaabaaabababbbaaabbbbababaabbaabbbabaaaabbbbabbaaaababbaababaabaaabbaabbabbbbabaaabbabaaaaabbbaaababababaaaabbaabbbbbaaaaaabbbbababaababababbaabbaaabaaabbabbaabbbaaabbaaaabbbbaaabbbaabaaaaaaaaababbabbbaaaabbaabbbaabbbabbbbbabbaababbbaabaababaaaabbaabababbbabbababbaababbabbaaabbaababbaaaabbbbabaaaabbbbbaababaaabbaaaaababbababbbaaaaabbbbabbabaabbababbaaabbbbbaaaaaaaabbaaabbaabababaabbaaaaaaaaabbaabaaaaaaaabaaabbaaaabbbabaaaaaabaaabaaaababbaabababbbaaaaabababbbaababababaabaabbaaabbbbaaaabbbbababbaabaaaababbbbbbbaaabaaabaaaababaababbabaababbabaaabababbaabaaaababaabaabbabaaabbbababbabbabbabbbbbababbbbabaaabbababaaabaaaaabbbbbabababaababbbabbaabaabbbbbaaaaababababbbabbaabababababaabaaababbaaaabaaabaaaabaaabbbbaaababaabaaabaaabaaaaabbabaabbbbaaabbbbbaabbabababbbbbabbbbbbaaaabbbbbbbaabbbbbbaababbbabababaaabbaaaabababbbabbbbbababbabbbaaabaabbbbbbaaabbabbaabbbaabaaabaabbbbbbbbabbbaaaaaaaaabbababbbaaaaaaaaabbbabbbabbabaaaabaaababaaaabaabbababaaaaaaababababbbaababababbaaabbaabaaaaaabaabbaabababbabaaaaabbaabaaabaabbbbaabbbbababbbaabbbbabaaaaaabbababababbbaabaaaaabaaabaabaaaabbabbbaaababbaabababbaabababbabbbabbbaaaaabbbabaaabbbaaaabbbbababbabbabbbaaabbababbbabbbabbbbaaaababaaaabaababbaabbbabababababbbbabbabbababaababbaababbaabbabaaababbbaaabbbaababbbaabbbbaabaabbaaaaabbbbaaabbaabbababbaabbababbbbbbbaaaababbaaababbbaabbabababaabaababaaaaaabaaabbaaababbbababbababbbaabaabaaababababbbaaabbbbbbaabbaaaaababbbbabbbbabaaabbbaaaabaaabaabbababbbaaaabbbabbbabababaababababbaabaababbbabbbbbabbabbabbbbbbbabbbaaabbbaaaaabbabaabbaaabbabaabbbaaabbababbabbaabbabaaaaaaabbabbbbaabaaabaaabbbbbabbaababaaabbbbbbabbabbbababbbbbaaabbbbaabbbabaabbabaaaabaaaaabaabbaabbbbabbbaababababaababaabababbbaabbbaaabaaaababbbababbbaaababbaabaaabbabaaabbaababbbbbaaabbbabaaabaabaababaabbababaabaaabbbabaabbaaaaabbabbaaaabbbbaaababaabbbaaaabbbaaabababbaabbbabaabbbbbaabaabbbaababbaabbbbaaabbabbaabbabbbbbbaaaababbaaabbaaabaaabbabbbaabaaabbabaaabbabababbabaaabbaaaabbabbababababaabbbbbabbaababaabbbbabbabbaaabbaabbaaabbabbbabababaaaaabbaabbbaabbbaaabbbababaaaababbbbabaababbabbbabbbabbaaaaaaaabbbabbbbbbaaaabaabbbbbaaaabababbabbbabaaaababbababbbbbbabaabbabbbbaabbabbaabaaabbabaababbaabaabbabbbbaaaaabaaaabaaabbbbbbbbaaaabaaaabaabaabaaabbaabbbaaaaabababbaaabbbbbbbbbabaabaabbaababbbababbbbbbbbbbababababaaaababaabaaabbabbabbabbbbbabbbabbaaabbbababbaaaaabbababbbbaababbabaaabbbaabaabaaaabaabaabbbbabbbabbabaabbbbabaabaabaabababababbabbababbaaaabaabaabababbabaaaababbbaaabaabaaabaabababbbaabbbbabaaabababaaaaaabaaaaabbaaaaabbbaababbbbbbbbbbaabaabbaabaaababbabbbbbababbababababaabaabbbbbabbaababaabbaaaaabaabbaaabababbaabbbaaaababaaabbaaabaaabbababbbaaaaaaaabbaaabbbaaaaabbbbabbabbbabbbaaabaaaaabbabbaaabbaaabbabaaaababbbaabbaabbbaabababaabbbbbabbaabbabbbbbabaabaaabaaababaabbbbaabbababbaabaabbbbaabbaaabbbbbbaabaabaabbbaaabbabbbbbbabbaabaabaaaabbbbbbbaaabbbbbbbbaabbabaaaaabbbaababaabaaaaaaaabbaabaababbbbaaaabbabbabbbbbaaaababaaaabbaaaabaaabbaaaaabbbaaaabababaaaaaaaaaaabaabaaaaabaaaaabbaababbbabbbaaababaabbaabbbaaaabababaabbaabbaabbaabaaabaabaabbbaaaaaabaaaaaabaabaaabbbbabbbaaababbababaabbaaababbababaaabbbaabbbbbbaaabaaabbbbaabaaabaaabbabbbbbbbaababaababbaaabaaaabbababbbababaabaabbaaaaaabbaababbababbbbaabbabbaaaaaabbabaaaaaababbbbaaaabaaaabaaabaaabbbabbbbaababababaabbbaaaaabbabaabbaabaaabbbaabaaaabbaaabbbbaaabaaaaababbbbbbbabbbabaabbababaaaaaababababaaababbbbabaaaabababaaabbbaababbbbbaaaababaaaabbbabbaabbabaaabaaaabaaabaaaabaaaababbababbbabaaaaaaababbabaaaabbbabbabbabbbbaaabababbabaaabbbbbbababbabbaabbaaaaaabaaabbbabbaabaaaaaabbaaabababbbaaaaabaabaaabbbbbabaabbbabbbabbaaababbbbbababaaaaabbaaaabababbbabbbabaaaaaaabbabbbbbaaaaababbbabababbabababbbaabaaaababbbbbaaababaabaabaabaabbaabbabbaababaaabbbababbbaaababbbabbabbbbbbabbabbbaabaaabbbaaabbbaabaaabaaabbbabaababaaabbababbabbbbaabbabababaabbbabbabbababbaaaaaaaaaabaababbaaabaaaaaaabbbbaaabbbbbbaaabbbbbbaabababaabbbabbbbaabaaabbbabaabbbbbaaabbbababaaabaaaabbbbbbabbabaabaaabbbbbabbbaaaaabbbaaaaababbabbbbabbaaabbbabbaabaaabbbaabaabaababbabbabbbbabaabababbbaabbabbabbababbbbabbbabbbbbabaaabaaaabaabbaaaaaaabbaaabbbbbababbaaaabbbaaaaaaaaababbbbaabbbbbbbabbaabbbbaabaaaaaaaababbbbabaabbbbbbbabaaabbbbbabbabaabbaaabaaaabbbaabababaaabbbaabbaabaabbbaaababbbaaabbaaabaaabbbabaaabababaaaaaaaaaaababbabaabbbbbbbaabbbbbababbbabbaabaaabababbabbbbababbaaabbaabbbabbbbbbbabbbaaabbabbababbbaaaaabbbabaaabbbabbbbbbaaaabbbabbbaababbaabbbabbabbabbbbbabaabbbbabaaabababbaabaabaaaaabbbabbaaaaaaabbabaabaabbaaaaabaabaaaaabaababbababbaaaaabbbabbbbbabbabaababbaababaababbaaaaaaaaaaaabbabaaabbbbbabbabbbbabbbbbbaabaabaabbbababbbabbaabaabaabababbaaaabbbabbbbbbaababbaabababbabbbaabbbabbaaabaababaaabbbaabaabaabaaabbbabbabaaababaaaababbbaabbbbababbaaaaabbaabaabaaaaaabaaaaababbbabbbbbaaabbbabaababbbabbabbaaababaaabaaaabbabbaabababbbbabaaabbaaaabaaabaaabbabbabbaaabbbababababbbaabaabaaabbababbbbaabbabbbaaaaabbaabaabbbbbbaaabbaabbbabbaababbbbaabaaaabbabbaabbaaaaaabbbaaabbababababbbbbaaaabbaaabbbbabaaaaaaababbaaabbabbbbbabbbbabbaaaaababbbabbbaaaabbbbababaaaabaaabbbbbaabaaaaaaaabbaaabbabbbbbbbababaababbbabbbbbbaabbbbbbabbbbbbbaabbbaaabaaaabbbabbabbabbbaabbaaaaaaabaaabaababaaabbbbababaaaaaabbbbaababababbabbbaaaabaaabaaaaabaaabbababbbbaaabaaaaabaaababaabbbabaabbbaaaababbababbaaaaaaabbbabbbaabaabbabbaabaaababaaaaabbbabbbabaaab";
    string s = "bababababa";
    Solution a;
    int result = a.minimumDeletions(s);
    std::cout << result << std::endl;
    return 0;
}
