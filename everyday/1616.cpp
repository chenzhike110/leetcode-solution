#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkHeadTailFormation(string a, string b) {
        if (a.size() == 1) return true;
        // a取头，b取尾
        string head = a;
        string tail = b;
        int indexA = 0;
        int indexB = b.size()-1;
        while(true) {
            if(head[indexA] == tail[indexB]){
                indexA ++;
                indexB --;
            }
            else if(tail == b){
                tail = a;
            }
            else {
                return false;
            }
            if(indexA >= indexB) return true;
        }
    }
    bool checkPalindromeFormation(string a, string b) {
        bool res = checkHeadTailFormation(a, b)? true : checkHeadTailFormation(b, a);

        if(!res) {
            string ar, br;
            ar.assign(a.rbegin(), a.rend());
            br.assign(b.rbegin(), b.rend());
            res = checkHeadTailFormation(ar, br)? true : checkHeadTailFormation(br, ar);
        }
        return res;
    }
};

int main() {
    string a = "abegeg";
    string b = "feccba";
    Solution s;
    bool res = s.checkPalindromeFormation(a, b);
    cout << res << endl;
    return 0;
}