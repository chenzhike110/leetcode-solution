from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        delta = []
        for i in range(len(gas)):
            delta.append(gas[i] - cost[i])
        
        remain = [delta[0]]
        # start from 0
        for i in range(1, len(gas)):
            remain.append(remain[-1]+delta[i])

        gap = min(remain)
        start = 0
        for i in range(len(gas)-1, -1, -1):
            if gap >= 0:
                return start
            gap += delta[i]
            start = i
        return -1

if __name__ == "__main__":
    gas = [5]
    cost = [4]
    ans = Solution().canCompleteCircuit(gas, cost)
    print(ans)

        