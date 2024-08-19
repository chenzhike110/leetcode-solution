from typing import List

class Solution:
    # iter
    def minimumValueSumIter(self, nums: List[int], andValues: List[int]) -> int:
        def dfs(i, j, and_value):

            and_value = and_value & nums[i]
            
            if i == len(nums) - 1:
                if  j == len(andValues) - 1 and and_value == andValues[-1]:
                    return nums[i]
                return float('inf')

            # split or not
            ans_split = float('inf')
            if and_value == andValues[j] and j < len(andValues) - 1:
                ans_split = dfs(i+1, j+1, -1) + nums[i]
            ans_none_split = dfs(i+1, j, and_value)
            ans = min(ans_none_split, ans_split)
            return ans
        
        ans = dfs(0, 0, -1)
        if ans == float('inf'):
            ans = -1
        return ans
    
    def minimumValueSumDP(self, nums: List[int], andValues: List[int]) -> int:
        dp = [[set() for _ in range(len(andValues))] for _ in range(len(nums))]
        dp[0][0].add((nums[0], 0))

        for i in range(1, len(nums)):
            for j in range(min(i, len(andValues))):
                for situ in dp[i-1][j]:
                    # not split
                    dp[i][j].add((situ[0]&nums[i], situ[1]))
                    if situ[0] == andValues[j] and j < len(andValues) - 1:
                        dp[i][j+1].add((nums[i], situ[1]+nums[i-1]))
        
        min_value = float('inf')
        for situ in dp[-1][-1]:
            if situ[0] == andValues[-1]:
                min_value = min(min_value, situ[1]+nums[-1])
        if min_value == float('inf'):
            min_value = -1
        return min_value
    
if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]#[2,3,5,7,7,7,5]
    andValues = [2]#[0,7,5]
    ans = s.minimumValueSumDP(nums, andValues)
    print(ans)