# [0, n]内有多少个整数的二进制不存在连续的1

class Solution:
    def findIntegers(self, n: int) -> int:
        length = n.bit_length()
        dp = [[[0, set()] for _ in range(2)] for _ in range(length)]
        dp[0][1] = [1, ('1')]

        if length == 1:
            return 2

        ans = 1 + 1 # plus 0
        for i in range(1, length-1):
            dp[i][0][0] = dp[i-1][0][0] + dp[i-1][1][0]
            dp[i][1][0] = dp[i-1][0][0]

            ans += dp[i][0][0] + dp[i][1][0]

            dp[i][0][1].update(set([char+'0' for char in dp[i-1][0][1]]))
            dp[i][0][1].update(set([char+'0' for char in dp[i-1][1][1]]))
            dp[i][1][1].update(set([char+'1' for char in dp[i-1][0][1]]))
        
        for char in dp[length-2][0][1]:
            if int(char+'0', 2) <= n:
                ans += 1
            if int(char+'1', 2) <= n:
                ans += 1
        for char in dp[length-2][1][1]:
            if int(char+'0', 2) <= n:
                ans += 1
        return ans
    
if __name__ == "__main__":
    s = Solution()
    ans = s.findIntegers(3)
    print(ans)


        