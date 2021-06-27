#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    pair<int, int> get_index(int id, int n){
        int line = n-(id-1)/n-1;
        int row = (id-1)%n;
        if(((id-1)/n)%2==1){
            row = n - 1 - (id-1)%n;
        }
        return {line, row};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        static vector<int> arrived(n*n+1);
        q.emplace(1,0);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(int i=1;i<=6;i++){
                int nxt = p.first + i;
                if(nxt>n*n){
                    break;
                }
                auto nextnode = get_index(nxt, n);
                if(board[nextnode.first][nextnode.second]>=0){
                    nxt = board[nextnode.first][nextnode.second];
                }
                if(nxt == n*n){
                    return p.second+1;
                }
                if(!arrived[nxt]){
                    arrived[nxt]=1;
                    q.emplace(nxt, p.second+1);
                }
            }
        }
        return -1;
    }
};