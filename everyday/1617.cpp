#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge: edges) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].emplace_back(y);
            graph[y].emplace_back(x);
        }
        function<int(int, int&, int&)> dfs = [&](int root, int& mask, int& distance) {
            int first = 0, second = 0;
            // 去掉Root节点防止重复遍历
            mask &= ~ (1 << root);
            for (int vertex : graph[root]) {
                // 检查mask是否包括当前节点
                if (mask & (1 << vertex)) {
                    // 去掉当前节点
                    mask &= ~ (1 << vertex);
                    int distance = dfs(vertex, mask, distance) + 1;
                    if (distance > first) {
                        second = first;
                        first = distance;
                    }
                    else if(distance > second) {
                        second = distance;
                    }
                }
            }
            distance = max(distance, first + second);
            return first;
        };

        vector<int> ans(n - 1);
        for (int i = 1; i < (1 << n); i++) {
            int root = 4*8 - __builtin_clz(i) - 1;
            int mask = i;
            int distance = 0;
            dfs(root, mask, distance);
            if (mask == 0 && distance > 0) {
                ans[distance -1 ] += 1;
            }
        }
        return ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges({{1,2},{2,3},{2,4}});
    return 0;
}