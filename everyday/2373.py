from typing import List

class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        result = []
        for i in range(len(grid)-2):
            line = []
            for j in range(len(grid[0])-2):
                line.append(max(grid[i][j:j+3]+grid[i+1][j:j+3]+grid[i+2][j:j+3]))
            result.append(line)
        return result

if __name__ == "__main__":
    # grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
    a = Solution()
    print(a.largestLocal(grid))