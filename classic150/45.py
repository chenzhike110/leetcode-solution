from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [float('inf')] * len(nums)
        dp[0] = 0

        current_max = 0

        for i in range(len(nums)):
            for j in range(current_max+1, i+nums[i]+1):
                if j >= len(nums):
                    break
                dp[j] = dp[i] + 1
            current_max = max(current_max, i+nums[i])
            if current_max > len(nums):
                break
            
        return dp[-1]
    
if __name__ == "__main__":
    nums = [2,3,1,1,4]
    s = Solution().jump(nums)
    print(s)