from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_ = 0
        for i in range(len(nums)):
            if i > max_:
                return False
            else:
                max_ = max(max_, i+nums[i])
        
        return True
    
if __name__ == "__main__":
    nums = [1,0,8,0]
    ans = Solution().canJump(nums)
    print(ans)