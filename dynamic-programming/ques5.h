class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 0;
        int begin = 0;
        bool lpd[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            lpd[i][i]=true;
        }
        for(int i=1;i<s.length();i++){
            for(int j=0;j<i;j++){
                lpd[j][i]=false;
                if(s[i]==s[j]){
                    if(i-j==1) lpd[j][i] = true;
                    else if(lpd[j+1][i-1]) lpd[j][i] = true;
                    if(lpd[j][i] && i-j>maxlength) {
                        maxlength = i-j;
                        begin = j;
                    }
                }
            }
        }
        return s.substr(begin, maxlength+1);
    }
};
