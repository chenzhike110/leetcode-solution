from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        front = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                front[i] = front[i-1] + 1

        back = [1] * len(ratings)
        for i in range(len(ratings)-1, 0, -1):
            if ratings[i-1] > ratings[i]:
                back[i-1] = back[i] + 1

        candies = 0
        for i in range(len(ratings)):
            candies += max(front[i], back[i])

        return candies
    
if __name__ == "__main__":
    ratings = [1,2,2]
    ans = Solution().candy(ratings)
    print(ans)

        