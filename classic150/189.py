from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        tmp = nums[-k:].copy()
        nums[k:] = nums[:-k]
        nums[:k] = tmp

if __name__ == "__main__":
    nums = [1,2]
    k = 3
    Solution().rotate(nums, k)
    print(nums)