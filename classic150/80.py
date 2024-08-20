from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 1
        last_i = nums[0]
        index = 1
        while True:
            if index >= len(nums):
                break
            if nums[index] == last_i:
                count += 1
            else:
                count = 1
                last_i = nums[index]
            
            if count > 2:
                nums.pop(index)
                count -= 1
                index -= 1
            index += 1

        return len(nums)

if __name__ == "__main__":
    nums = [1]
    s = Solution().removeDuplicates(nums)
    print(s, nums)
            