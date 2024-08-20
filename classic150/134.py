from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        candidate = [[0 for _ in range(len(gas))] for _ in range(len(gas))]
        