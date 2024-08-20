from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i=j=0
        ans = []
        while i<m or j<n:
            if i == m:
                ans.append(nums2[j])
                j += 1
                continue
            
            if j == n:
                ans.append(nums1[i])
                i += 1
                continue
            
            if nums1[i] < nums2[j]:
                ans.append(nums1[i])
                i += 1
                continue

            if nums1[i] >= nums2[j]:
                ans.append(nums2[j])
                j += 1

        nums1[:] = ans[:]

if __name__ == "__main__":
    nums1 = [1,2,3,0,0,0]
    nums2 = [2,5,6]
    m = 3
    n = 3
    s = Solution()
    s.merge(nums1, m, nums2, n)
    print(nums1)