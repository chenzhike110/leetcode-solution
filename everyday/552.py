# 给定n，枚举所有由ALP组成的字符并满足A少于两个，L不会连续出现三个及以上

# force
class Solution:
    def checkRecord(self, n: int) -> int:
        situation = [['A', 'L', 'P']]
        for i in range(1, n):
            last = situation[-1]
            curr = []
            for char in last:
                if char.count('A') < 1:
                    curr.append(char+'A')
                if not char.endswith('LL'):
                    curr.append(char+'L')
                curr.append(char+'P')
            situation.append(curr)
        return len(situation[-1])
    
# dp
class Solution_DP:
    def checkRecord(self, n:int) -> int:
        dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(2)]
        # n, a, l
        dp[0][0][0] = 1 # P
        dp[0][1][0] = 1 # A
        dp[0][0][1] = 1 # L

        for i in range(1, n):
            dp[i%2][0][0] = dp[(i-1)%2][0][0] + dp[(i-1)%2][0][1] + dp[(i-1)%2][0][2]
            dp[i%2][1][0] = dp[(i-1)%2][1][0] + dp[(i-1)%2][1][1] + dp[(i-1)%2][1][2] + dp[(i-1)%2][0][0] + dp[(i-1)%2][0][1] + dp[(i-1)%2][0][2]
            dp[i%2][0][1] = dp[(i-1)%2][0][0]
            dp[i%2][1][1] = dp[(i-1)%2][1][0]
            dp[i%2][0][2] = dp[(i-1)%2][0][1]
            dp[i%2][1][2] = dp[(i-1)%2][1][1]

        return sum(dp[(n-1)%2][1] + dp[(n-1)%2][0])% (10**9 + 7)

if __name__ == "__main__":
    s = Solution_DP()
    ans = s.checkRecord(93573)
    print(ans)