#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string printBin(double num) {
        string result="0.";
        for(int i=0;i<32;i++) {
            num = num * 2.0;
            if (num >= 1.0) {
                result = result+"1";
                num = num - 1;
            }
            else {
                result = result+"0";
            }
            if (num < 1e-6) break;
            // std::cout << num << std::endl;
        }
        if (num > 1e-6)
            return "ERROR";
        return result;
    }
};

int main() {
    auto a = Solution();
    string result = a.printBin(0.1);
    std::cout << result << std::endl;
}