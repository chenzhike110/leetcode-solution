# down 1 or up 2^n to kth stair

class Solution:
    def waysToReachStair_dfs(self, k: int) -> int:
        def dfs(current, target, jump, last_back):
            ans = 0
            if current == target:
                ans = 1
            elif current > target + 1:
                return 0

            
            if not last_back:
                ans += dfs(current-1, target, jump, True)
            ans += dfs(current+2**jump, target, jump+1, False)
            return ans
        result = dfs(1, k, 0, False)
        return result

if __name__ == "__main__":
    s = Solution()
    ans = s.waysToReachStair(0)
    print(ans)
