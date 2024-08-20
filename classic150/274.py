from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        H = min(citations[0], len(citations))
        for i in range(1, len(citations)):
            remain = len(citations) - i
            minimum = citations[i]
            if remain < minimum:
                H = max(H, min(remain, minimum))
                break
            else:
                H = minimum
        
        return H
    
if __name__ == "__main__":
    citations = [4,4,0,0]
    ans = Solution().hIndex(citations)
    print(ans)
