from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        before = [1] * (len(nums) + 1)
        after = [1] * (len(nums) + 1)
        ans = [0] * len(nums)

        for i in range(len(nums)):
            before[i+1] = before[i] * nums[i]

        for i in range(len(nums)-1, 0, -1):
            after[i-1] = after[i] * nums[i]

        for i in range(len(nums)):
            ans[i] = before[i] * after[i]

        return ans
    
if __name__ == "__main__":
    nums = [1,2,3,4]
    ans = Solution().productExceptSelf(nums)
    print(ans)