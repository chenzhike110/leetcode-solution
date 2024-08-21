class Solution:
    def romanToInt(self, s: str) -> int:
        maps = {
            'I':1,
            'V':5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000
        }

        last_c = s[-1]
        sum_ = 0
        for c in s[::-1]:
            if maps[c] < maps[last_c]:
                sum_ += -maps[c]
            else:
                sum_ += maps[c]
            last_c = c
        return sum_
    
if __name__ == "__main__":
    s = "MCMXCIV" #1994
    ans = Solution().romanToInt(s)
    print(ans)