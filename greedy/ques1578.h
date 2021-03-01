class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        bool deleting = false;
        int result = 0;
        int max = cost[0];
        for(int i=1;i<s.length();i++){
            if(deleting&&s[i]!=s[i-1]){
                deleting = false;
                max = 0;
            }
            if(deleting){
                if(cost[i]>max){
                    result+=max;
                    max=cost[i];
                }
                else{
                    result+=cost[i];
                }
            }
            if(s[i]==s[i-1]&&!deleting){
                deleting = true;
                max = cost[i-1]>cost[i]? cost[i-1]:cost[i];
                result += cost[i-1]+cost[i]-max;
            }
        }
        return result;
    }
};
