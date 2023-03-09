#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minimumRecolorsize = k;
        for(int j=0; j<k; j++) {
            if (blocks[j] == 'B') minimumRecolorsize --;
        }
        int tempRecolorsize = minimumRecolorsize;
        for(int i=0; i<blocks.size()-k; i++) {
            if (blocks[i+k] == 'B' && blocks[i] == 'W') tempRecolorsize -= 1;
            else if (blocks[i] == 'B' && blocks[i+k] == 'W') tempRecolorsize += 1;
            if (tempRecolorsize < minimumRecolorsize) minimumRecolorsize = tempRecolorsize;
            cout << tempRecolorsize << endl;
        }
        return minimumRecolorsize;
    }
};

int main() {
    string blocks = "WBWBBBW";
    int k = 2;
    Solution a;
    int result = a.minimumRecolors(blocks, k);
    cout << result << endl;
    return 0;
}